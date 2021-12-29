#include <thread>
#include <cassert>

int main(void) {
    bool called = false;
    std::thread my_thread([&]{called = true;});
    my_thread.join();
    assert(called); 
}

