#include <cassert>
#include <iostream>

using namespace std;

void func(int myarr[]) { 
    assert(sizeof(myarr)/sizeof(int) != 10); // tendency to do this
}

int main(void) {
    int* myarr = new int[10];
    assert(sizeof(myarr)/sizeof(int) == 2); // warning: 'sizeof (myarr)' will return the size of the pointer, not the array itself [-Wsizeof-pointer-div]
    func(myarr);
}

