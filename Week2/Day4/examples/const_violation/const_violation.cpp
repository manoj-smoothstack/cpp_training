#include <cassert>

void non_volatile(void) {
    const int x = 4;
    int *y = (int*)&x;
    *y = 7;
    assert(x == 4); // evaluated (optimized) at compile time
    assert(*(&x) != 7);
}

void vol(void) {
    const volatile int x = 4;
    int *y = (int*)&x;
    *y = 7;
    assert(x == 7); // evaluated (optimized) at compile time
    assert(*(&x) == 7);
}

int main(void) {
    non_volatile();
    vol();
}

