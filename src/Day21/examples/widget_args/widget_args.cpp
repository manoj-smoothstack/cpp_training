#include <thread>

class A {};

//void myfunc(A& data) { // /usr/lib/gcc/x86_64-redhat-linux/8/../../../../include/c++/8/thread:253:11: error: no matching member function for call to '_M_invoke'
void myfunc(const A& data) {}

int main(void) {
    A a;
    std::thread t(myfunc, a);
    t.join();
}

