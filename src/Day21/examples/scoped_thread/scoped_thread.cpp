
//          Copyright Anthony Williams
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)


#include <thread>
#include <iostream>

class scoped_thread {
    std::thread t;
public:
    explicit scoped_thread(std::thread t_): t(std::move(t_)) {
        if(!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() { // called when t loses scope in f()
        t.join();
    }
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};

void do_something_in_current_thread() {}

struct func {
    int& i;
    func(int& i_): i(i_) {}
    void do_something(int i) {}
    void operator() () {
        for (unsigned j = 0; j < 1000000; ++j) {
            do_something(i); // potential access to dangling reference
        }
    }
};

void f() {
    int some_local_state;
    scoped_thread t{std::thread(func(some_local_state))};
    do_something_in_current_thread();
}

int main(void) {
    f();
}

