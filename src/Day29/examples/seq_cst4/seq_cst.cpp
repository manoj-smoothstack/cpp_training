#include <atomic>
#include <cassert>
#include <thread>

std::atomic<int> x = {0}, y = {0}, z1 = {0}, z2 = {0};

void storex() { x.store(2, std::memory_order_seq_cst); }
void storey() { y.store(3, std::memory_order_seq_cst); }
void loadx() { z1 = x.load(std::memory_order_seq_cst); }
void loady() { z2 = y.load(std::memory_order_seq_cst); }
void thread1() {
    storex();
    loady();
}
void thread2() {
    storey();
    loadx();
}

int main(void) {
    int i = 0;
    while (++i < 10000) {
        std::thread t2(thread2);
        std::thread t1(thread1);
        t1.join();
        t2.join(); 
        assert(!(z1 == 0 && z2 == 0)); // success
        assert(!(z1 == 2 && z2 == 0)); // success
        //assert(!(z1 == 0 && z2 == 3)); // fail
        //assert(!(z1 == 2 && z2 == 3)); // fails
    }
}

