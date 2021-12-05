//Will the below code work? Why? Why not?
#include <cassert>
int main(void) {
    int expression = 2;
    switch(expression) {
      case 2:
        assert(expression == 2);
      case 3:
        assert(expression != 3);
    }
}

//Note there is no break. Once there is a match, the case blocks behave like OR operator that goes top to bottom in precedence.
