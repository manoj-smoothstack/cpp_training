#include <thread>

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

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach(); // Don't wait for thread to finish
    // new thread might still be running
}

int main(void) {
    //oops(); // gets Illegal instruction
}

