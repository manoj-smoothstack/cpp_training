#include <thread>
#include <cassert>

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_): t(t_) {}
    ~thread_guard() {
        if (t.joinable()) {
            t.join(); 
        }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};

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
    thread_guard g(t);
    do_something_in_current_thread();
}

int main(void) {
    try {
        f();
        assert(false);
    } catch (...) {
        assert(true);
    }
}

