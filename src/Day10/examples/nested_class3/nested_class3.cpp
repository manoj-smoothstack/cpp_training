#include <cassert>
#include <typeinfo>

class A {
private:
    class B { // inline class B inside class A
    public:
        int test = 7;
    };
public:
    typedef B btype;
};

int main(void) {
    A::btype b;
    assert(b.test == 7);
}


