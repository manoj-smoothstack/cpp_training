#include <atomic>
#include <thread>
#include <assert.h>
#include <iostream>

std::atomic<bool> x,y;
std::atomic<int> z;

void write_x_then_y() {
    y.store(true, std::memory_order_relaxed);
    x.store(true, std::memory_order_relaxed);
}
void read_y_then_x() {
    while (!y.load(std::memory_order_relaxed));
    if (x.load(std::memory_order_relaxed))
         ++z;
}

int main() {
    int i = 0;
    while (++i < 1000) {
        x = false;
        y = false;
        z = 0;
        std::thread a(write_x_then_y);
        std::thread b(read_y_then_x);
        a.join();
        b.join();
        assert(z.load() != 0);
    }
}

