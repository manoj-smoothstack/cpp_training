#include <cassert>

// You cannot use an if statement inside  macro this way
// Because the preprocessor cannot compile your statement
//#define SUM_A( x, y ) if ( x == 0 || y == 0) { 0 } else { x + y; }
//
//Instead you can define it using a ternary:

#define SUM_A( x, y )  ((x) == 0 || (y) == 0 ? 0 : (x + y))

// However you can do the following:
#define SUM_B( x, y ) ({int answer; if ( x == 0 || y == 0) { answer = 0; } else { answer = x + y; }; answer; })

int main(void) {
    assert(SUM_A(2, 5) == 7);
    assert(SUM_B(2, 5) == 7);
}


