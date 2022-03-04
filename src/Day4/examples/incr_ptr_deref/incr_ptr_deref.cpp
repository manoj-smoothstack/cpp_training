#include <cassert>
#include <iostream>

using namespace std;

int main(void) {
    int x = 10;
    int* y = &x;
    int* z = y;
    assert(*(y++) == 10); // y now points to an illegal location
    //assert(dynamic_cast<long>(z)+4 == dynamic_cast<long>(y)); // invalid target type 'long' for dynamic_cast; target type must be a reference or pointer type to a defined class
    //assert(static_cast<long>(z)+4 == static_cast<long>(y)); // error: static_cast from 'int *' to 'long' is not allowed
    assert((long)z+4 == (long)y);
}

