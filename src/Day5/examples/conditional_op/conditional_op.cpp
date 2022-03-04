//Is this code correct? Why? Why not?
#include <cassert>
int main(void) {
    int y = 2;
    int x;
    (y == 3 ? x : y) = 4;  // lvalue expression
    assert(y == 4);
}
