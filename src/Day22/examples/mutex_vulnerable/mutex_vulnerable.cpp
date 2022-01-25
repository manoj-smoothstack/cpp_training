#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex mtx;
int vuln1 = 10;
int vuln2 = 10;
void vulnerable() { 
    std::cout << "vulnerable " << std::this_thread::get_id() << std::endl;
    vuln1 = 11;
    vuln2 = 11;
}
void thread_saf() {
    std::cout << "thread safe " << std::this_thread::get_id() << std::endl;
    mtx.lock(); // lock does not seem to help
    vulnerable(); // as this function gets called by another thread
    vuln1 = 12;
    vuln2 = 12;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    mtx.unlock();
}
int main(void) {
    std::thread t1(thread_saf);
    std::thread t2(vulnerable);
    t1.join();
    t2.join(); 
    std::cout << vuln1 << std::endl; // both are either 11 or both are 12
    std::cout << vuln2 << std::endl; // a race condition scenario
}

