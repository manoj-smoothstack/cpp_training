#include <thread>
#include <vector>
#include <cassert>
#include <string>

thread_local int x; // thread-local variable at namespace scope

class X {
    static thread_local std::string s; // thread-local static class data member
};

thread_local std::string X::s; // definition of X::s is required

void foo() {
    thread_local std::vector<int> v; // a thread-local local variable
}

void myfunc() {
   assert(x == 0);
   x = 10;
}

int main(void) {
    x = 5;
    std::thread t1(myfunc);
    std::thread t2(myfunc);
    t1.join();
    t2.join();
}

