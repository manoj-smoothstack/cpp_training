#include <thread>

void another_func() {}

std::thread t3(another_func);
std::thread t4(another_func);

void some_func() {
    if (t3.joinable()) {
        t3.join();
    }
    if (t4.joinable()) {
        t4.join();
    }
}

int main(void) {
    std::thread t1(some_func);
    std::thread t2(some_func);
    t1.join();
    t2.join();
}

