#include <iostream>
#include <thread>
#include <mutex>

int vuln1 = 10;
int vuln2 = 10;
void vulnerable() { 
    std::cerr << std::endl << "vulnerable setting " << std::this_thread::get_id() << std::endl;
    vuln1 = 11;
    vuln2 = 11;
    std::cerr << std::endl << "vulnerable done " << std::this_thread::get_id() << std::endl;
}
void thread_saf() {
    std::mutex mtx;
    mtx.lock();
    std::cerr << std::endl << "lock thread safe setting " << std::this_thread::get_id() << std::endl;
    vuln1 = 12;
    vuln2 = 12;
    std::cerr << std::endl << "lock thread safe done " << std::this_thread::get_id() << std::endl;
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

// One possible output that shows how the vulnerable thread gets "evicted"
/*
vulnerable setting 140564060571392
lock thread safe setting 140564068964096

lock thread safe done 140564068964096


vulnerable done 140564060571392
11
11
*/

