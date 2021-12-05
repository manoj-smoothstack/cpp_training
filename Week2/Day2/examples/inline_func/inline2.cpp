#include <cassert>
  
extern inline int inlinefunc();

void callfunc() {
    assert(inlinefunc() == 3);
}

/*
With C++17, still get a warning.

inline20.cpp:3:19: warning: inline function 'inlinefunc' is not defined [-Wundefined-inline]
extern inline int inlinefunc();
                  ^
inline2.cpp:6:12: note: used here
    assert(inlinefunc() == 3);
           ^
1 warning generated.
*/
