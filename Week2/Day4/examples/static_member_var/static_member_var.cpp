//Member variables declared static are not bound to class instances.
//They exist even when no class instances are created.
#include <cassert>
  
class A {
    public:
        static int x; // declare inside the class, is public
        A() { assert(x == 4); }; // access inside the class
};

int A::x = 4; // initialize outside the class and all functions

int main(void) {
    A a;
    assert(A::x == 4);  // access outside the class
}
