#include <cassert>
class A {
    public:
        const static int x = 5; 
};
int main(void) {
    assert(A::x == 5);
}

// Defining it as const allows us to define it in line with the body.

