#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>

#define SAMPLE 5

template<typename T>
class threadsafe_queue {
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    threadsafe_queue() {}
    threadsafe_queue(threadsafe_queue const& other) {
        std::lock_guard<std::mutex> lk(other.mut);
        data_queue = other.data_queue;
    }
    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }

    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this] {return !data_queue.empty();});
        value = data_queue.front();
        data_queue.pop();
    }
    std::shared_ptr<T> wait_and_pop() {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this] {return !data_queue.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool try_pop(T& value) {
        std::cout << "try_pop2" << std::endl;
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    std::shared_ptr<T> try_pop() {
        std::cout << "try_pop2" << std::endl;
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool empty() const {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};

struct data_chunk { int x; };
data_chunk prepare_data(int ii) { 
    data_chunk d = { ii };
    std::cerr << "Prepare: " << d.x << std::endl;
    return d;
}
void process(data_chunk& d) { std::cerr << "Processing: " << d.x << std::endl; }
bool is_last_chunk(data_chunk& d) { return (d.x == SAMPLE-1) ; }

threadsafe_queue<data_chunk> data_queue;

void data_preparation_thread() {
    for (int ii = 0; ii < SAMPLE; ii++) {
        data_chunk const data = prepare_data(ii);
        data_queue.push(data);
    }
}

void data_processing_thread() {
    while (true) {
        data_chunk data;
        data_queue.wait_and_pop(data);
        process(data);
        if (is_last_chunk(data))
            break;
    }
}

int main() {
    std::thread t1(data_preparation_thread);
    std::thread t2(data_processing_thread);
    
    t1.join();
    t2.join();
}

