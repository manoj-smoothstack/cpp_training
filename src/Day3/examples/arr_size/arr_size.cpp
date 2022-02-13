#include <cassert>

int main(void) {
    int myarr[] = {2, 4, 5, 3};
    int myarr1[7] = {2, 4};
    assert(sizeof(myarr)/sizeof(int) == 4);
    assert(sizeof(myarr1)/sizeof(int) == 7);
}

