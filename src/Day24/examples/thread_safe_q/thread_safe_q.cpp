
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>

#define SAMPLE 5

template<typename T>
class threadsafe_queue {
private:
    std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }

    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        value=data_queue.front();
        data_queue.pop();
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

