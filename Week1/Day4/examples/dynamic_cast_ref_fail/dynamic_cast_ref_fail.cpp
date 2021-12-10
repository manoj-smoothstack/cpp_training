#include <cassert>
#include <typeinfo>
#include <cstdlib>

class A {
public:
    virtual void foo() {};
};
class C: public A { };

int main(void) {
    A a;
    A &a1 = dynamic_cast<A&>(a); // this does not fail
    C c1;
    A &a2 = dynamic_cast<A&>(c1); // this does not fail
    try {
        C &c = dynamic_cast<C&>(a); // this fails
    } catch(const std::bad_cast& e) {
        assert(true);
        exit(0);
    }
    C* d = dynamic_cast<C*>(&a); // this does not fail that we saw before
    assert(d != nullptr);
    assert(false);
}

