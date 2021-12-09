#include <cassert>

int main(void) {
    int myarr[0];
    assert(sizeof(myarr) == 0);

    int *myarr1 = new int[0];
    assert(sizeof(myarr1) == 8);

    int myarr2[true];
    myarr2[0] = 7;
    assert(myarr2[true-1] == 7);
}

