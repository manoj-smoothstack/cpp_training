#include <cassert>

class A {
public:
    virtual void foo() {};
};
class B: public A { };
class C: public A { };
int main(void) {
    A a;
    B b;
    A* pA = &b;
    B* pB = dynamic_cast<B*>(pA);  // this works OK, returns the expected pointer
    assert(pB != nullptr);
    C* pC = dynamic_cast<C*>(pA);  // this returns NULL because B isn't a C
    assert(pC == nullptr);
    pA = nullptr;
    pC = dynamic_cast<C*>(pA);  // this returns NULL because B isn't a C
    assert(pC == nullptr);
}

