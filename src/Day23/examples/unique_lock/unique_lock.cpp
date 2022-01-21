#include <algorithm>
#include <thread>
#include <mutex>

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
        if (&lhs == &rhs) return;
        std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
        std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
        std::lock(lock_a, lock_b);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

some_big_object s1, s2;
X x1(s1);
X x2(s2);

void call_swap() {
    swap(x1, x2);
}

void call_swap1() {
    swap(s1, s2);
}

int main(void) {
    std::thread thread1(call_swap);
    std::thread thread2(call_swap);
    thread1.join();
    thread2.join();

    std::thread thread3(call_swap1);
    std::thread thread4(call_swap1);
    thread3.join();
    thread4.join();
}

