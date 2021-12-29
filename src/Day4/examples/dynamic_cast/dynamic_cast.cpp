#include <string>

class A { };
class B : public A {
public:
    virtual void b() {};
};
class C: public B {
public:
    void b() {};
};
class E {
public:
    virtual void e() = 0;
};
class D {};

int main(void) {
    int *x = new int(10);
    //int *y = dynamic_cast<int*>(x); // error: 'int' is not a class type
    std::string s = "hello";
    //string s1 = dynamic_cast<string>(s); // error: invalid target type 'std::__cxx11::string' (aka 'basic_string<char>') for dynamic_cast; target type must be a reference or pointer type to a defined class
    A a;
    //B *b = dynamic_cast<B*>(&a); // error: 'A' is not polymorphic
    B b;
    C *c = dynamic_cast<C*>(&b); // base to derived works only with polymorphic classes
    A* d = dynamic_cast<A*>(&b); // derived to base conversion is fine
}

