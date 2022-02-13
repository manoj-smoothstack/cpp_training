#include <cassert>
class A {
    public:
        static int x;
        static void setx(int x) { A::x = x; };
};
int A::x;
int main(void) {
    A::setx(5);
    assert(A::x == 5);
}

// You can also use a static method to change x. Note that we never created an instance of A to do above. An instance of A was not involved.

