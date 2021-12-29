//This is a named variable or an alias.
//Allows us to use one variable interchangeably with another to modify the same value.
#include <cassert>
  
int main(void) {
    int y = 10;
    int& x = y; // x and y refer to the same location
    x = 7;
    assert(y == 7);
}

//A reference is required to be initialized to refer to a valid object or function.
//There are no references to void and no references to references.
