#include <cassert>
#include <iostream>

using namespace std;

int y = 0;
static bool destroyed = false; 

void myfunc() {
    static int x = 0; // initialized only once
    x++; // incremented each time
    y = x; // update a global non-static, but may not be thread safe
}

class A {
    public:
        ~A() { destroyed = !destroyed; assert(destroyed); };
};

int main(void) {
    static int x; // this x is in the scope of the main block
    { A a; } // declaring non-static variable of type A in inner block
    assert(destroyed); // the destructor must have been called
    {static A a;} // static variable of type A in inner block, this will live to end of program
    { static int x(2); }; // inner block x in local scope does not affect main scope
    x = 5; // setting main scope x to 5
    assert(x == 5);
    myfunc();
    myfunc();
    assert(y == 2);
    destroyed = false; // destructor is called just before exit, but after this line
    static class B {};
}

