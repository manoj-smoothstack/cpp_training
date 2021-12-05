#include <cassert>
  
int main(void) {
    assert(1+1+1 == 3);
    assert(.1+.1+.1 != .3);  // correct, but why?
}

/*
Floating point numbers are internally represented as base 2 or binary fractions. For example the decimal fraction 0.125 has value 1/10 + 2/100 + 5/1000. And the binary fraction 0.001 has value 0/2 + 0/4 + 1 / 8. Both these fractions have the same value of 0.125.

Unfortunately, most decimal fractions cannot be represented as binary fractions. The decimal floating point numbers you enter are only approximated by the binary floating point numbers. 

Just as 1 / 3 cannot be represented in decimal exactly (0.3 or 0.33 or 0.333 or….), the number 0.1 cannot be represented in binary exactly.

On most machines today, floats are approximated using a binary fraction with the numerator using the first 53 bits starting with the most significant bit and with the denominator as a power of two. In the case of 1/10, the binary fraction is 3602879701896397 / 2 ** 55 which is close to but not exactly equal to the true value of 1/10.

Why is that? 1/10 is not exactly representable as a binary fraction. IEEE-754 doubles contain 53 bits of precision, so on input the computer strives to convert 0.1 to the closest fraction it can of the form J/2**N where J is an integer containing exactly 53 bits.
*/
