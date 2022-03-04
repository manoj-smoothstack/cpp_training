//Regular C-style arrays can be passed as parameters to functions. 
#include <cassert>
using namespace std;

// arrays are passed by reference
void arrpass(int myarr[]) {
    myarr[2] = 6;
}

int main(void) {
    int myarr[10];
    myarr[2] = 7;
    arrpass(myarr);
    assert(myarr[2] == 6);
}

//The array itself is not passed, but only the address of it’s first element. The array behaves as if it is passed by reference.
