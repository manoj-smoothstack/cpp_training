#include <atomic>
#include <thread>
#include <assert.h>

std::atomic<bool> x,y;
std::atomic<int> z;

void write_x_then_y() {
    x.store(true, std::memory_order_seq_cst);
    y.store(true, std::memory_order_seq_cst);
}
void read_y_then_x() {
    while (!y.load(std::memory_order_seq_cst));
    if (x.load(std::memory_order_seq_cst))
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
        assert(z.load() == 1); // fails once in a while
    }
}

