#include <cassert>

int main(void) {
    unsigned int x = 1;
    unsigned int y = 2;
    x &= y; // 01 & 10
    assert(x == 0);
    x |= y; // 00 | 10
    assert(x == 2);
    x ^= 1; // 10 ^ 01
    assert(x == 3);
}

