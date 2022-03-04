#include <cassert>

int main(void) {
    int x = 4;
    // auto f = [x]() {assert(x == 2;}; // error: cannot assign to a variable captured by copy in a non-mutable lambda
    auto f = [x]() mutable {
        return x++ + 5;
    };
    assert(f() == 9); // x inside the lambda is now 5
    assert(f() == 10); // x inside the lambda is now 6
    assert(f() == 11); // and so on....
    assert(f() == 12);
    auto g = [&x]() { // passing by reference and no mutable here
        return x++ + 5;
    };
    assert(g() == 9);
    assert(x == 5); // x in main() scope is now changing
    assert(g() == 10);
}

