#include <cassert>
#include <cmath>

int main(void) {
    assert(floor(2.3) == 2);
    assert(floor(2.8) == 2);
    assert(floor(-2.3) == -3);
    assert(floor(-2.8) == -3);

    assert(ceil(2.3) == 3);
    assert(ceil(2.8) == 3);
    assert(ceil(-2.3) == -2);
    assert(ceil(-2.8) == -2);

    assert(round(2.3) == 2);
    assert(round(2.8) == 3);
    assert(round(-2.3) == -2);
    assert(round(-2.8) == -3);

    assert(trunc(2.3) == 2);
    assert(trunc(2.8) == 2);
    assert(trunc(-2.3) == -2);
    assert(trunc(-2.8) == -2);
}
