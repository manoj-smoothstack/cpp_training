/*
 * If the same non-virtual method is defined twice with two different sets of parameters, it is an overloaded method.
If a method with same parameters is declared in B, and the corresponding one in A is virtual, then the method in B overrides.
If a method with different parameters in B from those in A, but has the same name, then it is called redefined.
The redefined method may create a problem sometimes. As shown here, the unintended method is called, as the float is casted to int. The compiler did give a warning though.
It works differently depending upon you using a pointer instead of a value.
Using pointers with virtual methods works fine. Note g() is declared virtual in A.
But pointers with redefined methods do not work as intended. Note f() in B is not called.
*/

#include <string>
#include <cassert>

using namespace std;

class A {
    public:
        inline static string otype;
        void f(int x) { otype = "unintended"; };
        void f(int x, int y) { otype = "overload"; }; // overloading f
        virtual void g(int x) { otype = "base"; };
};

class B : public A {
    public:
        virtual void g(int x) { otype = "override"; };
        void f(float x) { otype = "redefined"; };
};

int main(void) {
    A().g(1);
    assert(A::otype == "base");
    A a = B();
    a.g(2);
    assert(A::otype == "base");
    a.f(2.4);
    assert(A::otype == "unintended");
    a.f(2, 4);
    assert(A::otype == "overload");
    B *b = new B();
    A* a1 = b;
    a1->g(2);
    assert(A::otype == "override");
    a1->f(2.4);
    assert(A::otype == "unintended");
}

