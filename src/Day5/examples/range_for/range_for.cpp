#include <cassert>

int main(void) {
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // the initializer may be an array
        a[0] += n;
    assert(a[0] == 15);
}

//An example above that shows an initializer can be an array.
