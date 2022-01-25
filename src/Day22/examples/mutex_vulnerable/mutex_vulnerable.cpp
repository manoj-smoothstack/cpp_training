#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex mtx;
void vulnerable() { 
    std::cout << "vulnerable " << std::this_thread::get_id() << std::endl;
}
void thread_saf() {
    std::cout << "thread safe " << std::this_thread::get_id() << std::endl;
    mtx.lock();
    vulnerable();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    mtx.unlock();
}
int main(void) {
    std::thread t1(thread_saf);
    std::thread t2(vulnerable);
    t1.join();
    t2.join(); 
}
