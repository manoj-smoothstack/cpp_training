#include <iostream>
#include <thread>
#include <mutex>

int vuln1 = 10;
int vuln2 = 10;
void vulnerable() { 
    std::cout << "vulnerable " << std::this_thread::get_id() << std::endl;
    vuln1 = 11;
    vuln2 = 11;
}
void thread_saf() {
    std::mutex mtx;
    mtx.lock();
    std::cout << "lock thread safe " << std::this_thread::get_id() << std::endl;
    vuln1 = 12;
    vuln2 = 12;
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

