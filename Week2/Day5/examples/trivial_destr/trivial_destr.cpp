/*
A non-trivial destructor in simplest terms is a user defined destructor.
In class A, the user defines a destructor. So is_trivially_destructible<A> returns false, meaning it is not trivial.
In class A, no destructor is defined. So it is a trivial destructor.
If an implicitly-declared destructor is not deleted, it is implicitly defined.
*/

#include <cassert>
#include <iostream>

using namespace std;

class A {
public:
    ~A() {};
};

class B {
public:
    B() {};
};

int main(void) {
    assert(!std::is_trivially_destructible<A>::value);
    assert(std::is_trivially_destructible<B>::value);
}
