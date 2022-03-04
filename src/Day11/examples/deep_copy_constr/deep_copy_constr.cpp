#include <cassert>

class B {
    public:
        int myint;
        B(int myint) {
            this->myint = myint;
        }
};

class A {
    public:
        B *obj = nullptr; // required due to copy constructor
        A(B* obj) { this->obj = obj; }; // regular constructor called during initialization
        A(const A& a) { // copy constructor called when a is assigned to a1
           if (this->obj != nullptr) delete this->obj; // avoid memory leaks
           this->obj = new B(a.obj->myint); // deep copy
        }
};

int main(void) {
    B *b = new B{10};
    A a(b); // store a pointer inside a
    A a1 = a; // a1's copy constructor is called, does deep copy
    assert(a1.obj->myint == 10); // a1's obj contains initial value
    b->myint = 11;  // we modify the pointer's value
    assert(a.obj->myint == 11); // a's object reflects the change
    assert(a1.obj->myint == 10); // a1 has a copy, so it's not affected!
    a = a1; // copy constructor of a is called
    assert(a.obj->myint == 10); // a gets it's value from a1's obj
}

