#include <thread>
#include <cassert>

class X {
public:
    inline static bool called = false;
    void do_lengthy_work() { called = true; }
};

int main(void) {
    X my_x;
    std::thread t(&X::do_lengthy_work, &my_x);	
    t.join();
    assert(X::called);
}

