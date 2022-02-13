#include <atomic>
#include <thread>
#include <cassert>

std::atomic<int> x, y, r1, r2;

void thread1() {
    x.store(1, std::memory_order_relaxed); // A
    y.store(1, std::memory_order_relaxed); // B
}
void thread2() {
    r1 = y.fetch_add(1, std::memory_order_relaxed); // C
    r2 = y.load(std::memory_order_relaxed); // D
}
int main(void) {
    int i = 0;
    while (++i < 100000) {
        x = 0, y = 0, r1 = 0, r2 = 0;
        std::thread t1(thread1);
        std::thread t2(thread2);
        t1.join();
        t2.join();
        assert((r1 == 1 && r2 == 2) || (r1 == 0) && (r2 == 1));
    }
}

