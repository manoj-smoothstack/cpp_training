
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <cassert>
#include <thread>

struct func {
    int& i;
    func(int& i_): i(i_) {}
    void do_something(int i) {}
    void operator() () {
        for (unsigned j = 0; j < 100000000; ++j) {
            do_something(i); // potential access to dangling reference
        }
    }
};

void do_something_in_current_thread() {throw "Unexpected error";}

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try {
        do_something_in_current_thread();
    } catch(...) {
        t.join();
        throw;
    }
    t.join();
}

int main(void) {
    try {
        f();
        assert(false);
    } catch (...) {
        assert(true);
    }
}

