#include <cassert>
  
class A {
    public:
        bool comparator(int x, int y) {
            return x < y;
        }
};

int main(void) {
    A a;
    bool (A::*lessthan)(int, int)  = &A::comparator; // lvalue is function pointer definition
    assert((a.*lessthan)(2, 4)); // we invoke the pointer variable like a function call
}
