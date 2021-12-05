//Generally used if you do not need to compute a value more than N times, where N is known at compile time, and the computation is fairly complex or expensive.
#include <cassert>
  
constexpr unsigned int factorial(unsigned int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main(void) {
    constexpr int magic_value = factorial(5);
    assert(magic_value == 120);
}

//5 is a literal, but if it was a variable, the compiler traces its origin.

