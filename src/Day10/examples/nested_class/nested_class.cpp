#include <cassert>

class A {
private:
    class B { // inline class B inside class A
    public:
        const int x = 4;
    };
    B priv_b; // we force one instance to be created so we can use decltype
public:
    B getB() { return B(); }
    decltype(priv_b) y; // we can now use decltype
};

int main(void) {
    A a;
    //B b1 = a.getB(); // error: unknown type name 'B'
    auto b = a.getB(); // with auto, we do not need to declare a type
    assert(b.x == 4);
    decltype(a.y) b2 = a.getB(); // we can now create a variable of type B
}


