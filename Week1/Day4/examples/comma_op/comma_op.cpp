// The the result of the RHS is the last expression, but it's value is dependent upon the first 2 expressions, of which two of them alter it's value.
#include <cassert>  
int main() {
    int n = 1;
    int m = (++n, assert(n == 2), ++n, 2*n);
    assert(m == 6);
}
