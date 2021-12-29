#include <cassert>
const int func() { return 5; }
int main(void) {
    int expression = 2;
    const int x = func();
    /*
    switch(expression) {
      case x:
        break;
      default:
        assert(expression != 2);
    }
*/
}
//Case value is not a constant expression.
/*
case_nonconst.cpp:7:12: error: case value is not a constant expression
      case x:
           ^
case_nonconst.cpp:7:12: note: initializer of 'x' is not a constant expression
case_nonconst.cpp:5:15: note: declared here
    const int x = func();
              ^
1 error generated.
make: *** [Makefile:32: case_nonconst.o] Error 1
*/
