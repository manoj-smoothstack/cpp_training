#include <cassert>
  
constexpr unsigned int factorial(unsigned int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main(void) {
    const int x = 5; // this must be declared const
    constexpr int magic_value = factorial(x);
    assert(magic_value == 120);
}

