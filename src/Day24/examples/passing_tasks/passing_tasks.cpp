
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>
#include <cmath>
#include <iostream>
#include <ctime>

std::mutex m;
std::deque<std::packaged_task<void()> > tasks;

bool gui_shutdown_message_received() { 
    return (rand() % 5 == 2); 
};
void get_and_process_gui_message() {}

void gui_thread() {
    while(!gui_shutdown_message_received()) {
        get_and_process_gui_message();
        std::packaged_task<void()> task; {
            std::lock_guard<std::mutex> lk(m);
            if(tasks.empty())
                continue;
            task=std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

std::thread gui_bg_thread(gui_thread);

template<typename Func>
std::future<void> post_task_for_gui_thread(Func f) {
    std::packaged_task<void()> task(f);
    std::future<void> res = task.get_future();
    std::lock_guard<std::mutex> lk(m);
    tasks.push_back(std::move(task));
    return res;
}

int main(void) {
    std::future<void> the_future = post_task_for_gui_thread(gui_thread);
    gui_bg_thread.join();
}

