/*
Built-in support for all numeric types in C++
Limited support for pointer type (+, +=, -, -=, ++, --)
Modulus or % operator is not supported for float, double, long double
Why does the program below work?
*/

#include <cassert>
  
int main(void) {
    int x = 4;
    int y = x+++2;

    assert(y == 6);
    assert(x == 5);
}
