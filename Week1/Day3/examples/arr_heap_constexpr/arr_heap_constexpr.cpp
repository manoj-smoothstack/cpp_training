#include <cassert>

int main(void) {
    constexpr int sz = 10;
    int* myarr = new int[sz];
    assert(sizeof(myarr)/sizeof(int) == 2);
    //int newarr[] = (int[])myarr; // error: C-style cast from 'int *' to 'int []' is not allowed
}

