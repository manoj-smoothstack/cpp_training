#include <cassert>
#include "inline.h"

extern void callfunc();

int main(void) {
    assert(inlinefunc() == 3);
    callfunc();
}
