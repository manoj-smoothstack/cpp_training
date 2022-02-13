//What blocks are executed in the below example?
#include <cassert>
int main(void) {
    int expression = 2;
    switch(expression) {
      case 1+1:
        break;
      default:
        assert(expression != 2);
    }
}

// Only the case block, due to the break. Case can support the const expression.
