#include <cassert>

int func() { return 10; }

int main(void) {
    int n = func();
    //short myarr[n] = {0}; // error: variable-sized object may not be initialized
    short myarr[n];
    assert(sizeof(myarr)/sizeof(short) == n);
}

