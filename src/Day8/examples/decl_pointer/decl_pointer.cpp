//A pointer can be simply declared as below:
#include <cassert>
  
int main(void) {
    int n;
    int* np = &n; // RHS showing address-of operator
    *np = 4;
    assert(n == 4);
}

/*
The pointer declaration uses the address-of operator “&”.
This example shows a pointer to a stack variable of type int*.
The underlying value can be initialized through the pointer using the “*” dereference operator.
The “*” has dual semantics. It is also used for pointer declaration.
*/
