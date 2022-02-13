#include <thread>
#include <cassert>

std::atomic<int> x, y, r1, r2;

void thread1() {
    r1 = y.load(std::memory_order_relaxed);
    if (r1 == 42) x.store(r1, std::memory_order_relaxed);
}
void thread2() {
    r2 = x.load(std::memory_order_relaxed);
    if (r2 == 42) y.store(42, std::memory_order_relaxed);
}

int main(void) {
    int i = 0;
    while (++i < 1000) {
        std::thread t1(thread1);
        std::thread t2(thread2);
        t1.join();
        t2.join();
        assert(r1 != 42 && r2 != 42);
    }
}
