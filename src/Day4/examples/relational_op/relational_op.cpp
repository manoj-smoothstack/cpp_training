//Examine the following expressions and why do they behave this way?

#include <cassert>
float getf() {
    return 3.1;
}
float getf1() {
    return 3.0;
}
int main(void) {
    assert(true > false);
    assert(true > 0);
    float f = 3.0;
    assert(f/3.0 == 1);  // float precision did not kick in
    f = getf1();
    assert(f/3.0 == 1);  // exact representation of float
    f = getf();
    assert(f/3.1 != 1);  // float precision kicked in
    f = 3.1;
    assert(f/3.1 != 1); // float precision kicked in
    assert(3.1/3.1 == 1);  // compiler optimizes?
    assert((1.0/3)*3 == 1); //  compiler optimizes
    int x = 3;
    assert((1.0/x)*x == 1);
    x = 4;
    assert((1.0/x)*x == 1);
    assert((1/x)*x != 1); // integer division
}

