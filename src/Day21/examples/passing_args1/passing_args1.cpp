
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


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

