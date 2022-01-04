// Members that are static can be modified though.

#include <cassert>
  
class A {
    public:
        static int x;
        void func() const {
            x = 2;  // works, but may not be thread-safe!
        }
};

int A::x;

int main(void) {
    (new A())->func();
    assert(A::x == 2);
}

