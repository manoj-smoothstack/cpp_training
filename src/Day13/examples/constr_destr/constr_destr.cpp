#include <cassert>
#include <string>

using namespace std;

class A {
    public:
        inline static string order;
        A() {
            order += "A";
        }
        ~A() { order += "~A"; };
};

class B : public A {
    public:
        B() {
            order += "B";
        }
        ~B() { order += "~B"; };
};

class C : public B {
    public:
        C() {
            order += "C";
        }
        ~C() { order += "~C"; };
};

int main(void) {
    {C c;}
    assert(A::order == "ABC~C~B~A");
}
