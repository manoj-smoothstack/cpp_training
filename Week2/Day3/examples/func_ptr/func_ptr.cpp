#include <cassert>
  
bool comparator(int x, int y) {
    return x < y;
}

int main(void) {
    bool (*lessthan)(int, int) = &comparator; // lvalue is function pointer definition
    assert(lessthan(2, 4)); // we invoke the pointer variable like a function call
    assert((*lessthan)(2, 4)); // We can use this alternate syntax
}
