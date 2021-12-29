#include <cassert>  
int main(void) {
    int x = 0;
    bool res = (false && (1/x == 0));
    assert(!res);
}

