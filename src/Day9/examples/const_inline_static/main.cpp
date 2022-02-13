#include "static_inline.h"
  
extern void myfunc();

int main(void) {
    A a;
    assert(A::x == 4);  // access outside the class
    myfunc();
}

// inline is required if the static declaration is being included from .h files
