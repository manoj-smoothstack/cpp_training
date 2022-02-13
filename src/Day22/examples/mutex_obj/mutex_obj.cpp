#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

struct A;
void vulnerable(A&);

struct A {
    A() = default;
    A(const A&) = default;
    std::mutex mtx;
    int vuln = 10;
    void thread_saf() {
        std::cout << "thread safe " << std::this_thread::get_id() << std::endl;
        mtx.lock(); // lock does not seem to help
        vulnerable(*this); // as this function gets called by another thread
        vuln = 12;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mtx.unlock();
    }
};

void vulnerable(A& a) { 
    std::cout << "vulnerable " << std::this_thread::get_id() << std::endl;
    a.vuln = 11;
}

int main(void) {
    A a;
    std::thread t1(&A::thread_saf, std::ref(a));
    std::thread t2(vulnerable, std::ref(a));
    t1.join();
    t2.join(); 
    std::cout << a.vuln << std::endl; // prints either 11 or 12 (race condition)
}
