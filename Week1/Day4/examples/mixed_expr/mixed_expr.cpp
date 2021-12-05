#include <cassert>

/*
Does the following expression succeed?
assert(5/2 == 2.5);

5/2 performs an integer division and result is int 2.

Which of the following expressions will succeed?
*/

int main(void) {
    assert(5/2.0 == 2.5);
    assert(5.0/2 == 2.5);
    assert(5.0/2.0 == 2.5);
    assert((float)5/2 == 2.5);
    assert((float)(5/2) == 2.5);
}
