//Note we can put in a macro call or a function call as they are expressions too. We can have an assignment as one of the expressions too.
#include <cassert>
int main() {
    int n = 1;
    int m = (++n, assert(n == 2), m = 1, n+=m, ++n, 2*n);
    assert(m == 8);
}
