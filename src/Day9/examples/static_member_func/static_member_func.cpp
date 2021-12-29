#include <cassert>
  
class A {
    public:
        static int x;
        A() { };
        static void modx() { x = 5; };
};

int A::x;

int main(void) {
    A a;
    A::modx();
    assert(A::x == 5);
}
