#include <cassert>
  
int main() {
    int n = 2;
    int* p = &n;
    // pointers are convertible to bool
    if(    p && *p == 2   // "*p" is safe to use after "p &&"
       || !p &&  n != 2 ) // || has lower precedence than &&
        assert(true);
    else
        assert(false);
}
