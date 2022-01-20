#include <thread>
#include <cassert>>

int main(void) {
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    assert(hardware_threads == 2);
}

