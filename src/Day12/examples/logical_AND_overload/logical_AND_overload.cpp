#include <cassert>

class A {
private:
    bool flag;
public:
    inline static int called;
    A(bool f) : flag(f) {};
    operator bool() const { called++; return flag; };
};

int main(void) {
    A(false) && A(true); // does not get optimized out
    assert(A::called == 1); // short-circuting test
    A::called = 0;
    A(true) && A(false); // second condition has to be compared
    assert(A::called == 2); // short-circuiting not possible
}

