#include <cassert>
#include <string>

using namespace std;

class A {
    public:
        inline static string order;
        A(int z) {
            order += "A";
        }
        ~A() { order += "~A"; };
};

class B : public A {
    public:
        B(int y, int z) : A(z) {
            order += "B";
        }
        ~B() { order += "~B"; };
};

class C : public B {
    public:
        C(int x, int y, int z) : B(y, z) {
            order += "C";
        }
        ~C() { order += "~C"; };
};

int main(void) {
    {C c(1, 2, 3);}
    assert(A::order == "ABC~C~B~A");
}

