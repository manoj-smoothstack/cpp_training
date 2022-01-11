#include <algorithm>
#include <thread>
#include <mutex>
#include <iostream>

class some_big_object {};

void swap(some_big_object& lhs, some_big_object& rhs) {
    std::swap(lhs, rhs);
}

class X {
private:
    some_big_object some_detail;
    std::mutex m;
public:
    X(some_big_object const& sd) : some_detail (sd) {}

    friend void swap(X& lhs, X& rhs) {
        std::cout << "In swap thread_id = " << std::this_thread::get_id() << std::endl;
        if (&lhs == &rhs) return;
        std::cout << "Before scoped_lock thread_id = " << std::this_thread::get_id() << std::endl;
        std::scoped_lock guard(lhs.m,rhs.m);
        swap(lhs.some_detail, rhs.some_detail);
        std::cout << "After swap thread_id = " << std::this_thread::get_id() << std::endl;
    }
};

some_big_object s1, s2;
X x1(s1);
X x2(s2);

void call_swap() {
    swap(x1, x2);
}

int main(void) {
    //swap(x1, x2);
    std::thread thread1(call_swap);
    std::thread thread2(call_swap);
    thread1.join();
    thread2.join();
}

/*
Output:

In swap thread_id = 140418615289600
Before lock thread_id = 140418615289600
After lock thread_id = 140418615289600
After lock_guard thread_id = 140418615289600
After swap thread_id = 140418615289600
In swap thread_id = 140418606896896
Before lock thread_id = 140418606896896
After lock thread_id = 140418606896896
After lock_guard thread_id = 140418606896896
After swap thread_id = 140418606896896
*/

