
#include <thread>
#include <cassert>

class background_task {
public:
    inline static bool called = false;
    void operator()() const {called = true;};
};

int main(void) {
    background_task f;
    std::thread my_thread(f);
    my_thread.join();
    assert(background_task::called);
}

