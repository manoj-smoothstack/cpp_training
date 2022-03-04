
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

struct data_chunk { int x; };
data_chunk prepare_data(int ii) { 
    data_chunk d = { ii };
    std::cerr << "Prepare: " << d.x << std::endl;
    return d;
}
void process(data_chunk& d) { std::cerr << "Processing: " << d.x << std::endl; }
bool is_last_chunk(data_chunk& d) { return (d.x == SAMPLE-1) ; }

std::mutex mut;
std::queue<data_chunk> data_queue;
std::condition_variable data_cond;

void data_preparation_thread() {
    for (int ii = 0; ii < SAMPLE; ii++) {
        data_chunk const data = prepare_data(ii);
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
}

void data_processing_thread() {
    while (true) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [] { return !data_queue.empty(); } );
        data_chunk data = data_queue.front();
        data_queue.pop();
        lk.unlock();
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

