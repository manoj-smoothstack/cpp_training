#include <cassert>

int main(void) {
    unsigned int x = 1;
    x <<= 1;
    assert(x == 2);
    x <<= x;
    assert(x == 8);
    //1 <<= x; // expression is not assignable
    1 << x; // warning: expression result unused
    x = 1 << x;
    assert(x == 256);
}

