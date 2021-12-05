#include <cassert>

struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned short b : 3;
};

int main() {
    S s = {6};
    assert(++s.b == 7); // store the value 7 in the bit field
    assert(++s.b == 0); // the value 8 does not fit in this bit field
}

