#include <cassert>

class A {
public:
    class B {
    public:
        bool called = false;
        B() { called = true; }
    };
    class C {
    public:
        C() {}
    };
};

int main(void) {
    A::B b;
    assert(b.called);
}

