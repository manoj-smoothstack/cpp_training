#include <cassert>
  
void defarg(int x, int y = 2) {
    assert(x + y < 8);
}

int main(void) {
    defarg(5);
}

//Only trailing arguments can be default arguments.

