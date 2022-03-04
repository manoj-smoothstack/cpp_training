#include <cassert>
class A {
    public:
        static int x;
};
int A::x = 5;
int main(void) {
    assert(A::x == 5);
}

// If they are not const, they must be initialized outside the class and outside all functions.

