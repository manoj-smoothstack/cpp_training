#include <cassert>
class B {
    int i = 0;
    public:
        B(int i=0) {
            this->i = i;
        };
        int geti() {return i;}
};

class A {
    B b;
    public:
        A(B b = {1}) {  // we set default values for constructor
            this->b = b;
        }
        B getb() { return b; }
};

int main(void) {
    A a;
    assert(a.getb().geti() == 1);
}
