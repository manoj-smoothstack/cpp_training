#include <cassert>

struct B {
    int i;
    B() = default;
};

class A {
public:
    B& x;
    A(B& p) : x(p) {}
};

int main(void) {
    B b{};
    b.i = 10;
    A a(b);
    A a1 = a;
    b.i = 11;
    assert(a1.x.i == 11);
}

