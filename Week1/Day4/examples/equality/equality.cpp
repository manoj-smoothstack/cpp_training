//Why do the following expressions work?
#include <iostream>
#include <cassert>

using namespace std;

int main(void) {
    assert(3 == 3.0);
    assert(true == 1.0);
    assert('a' == 97);
   int* p = 0;
    assert(NULL == p);
    assert(NULL == 0);
}

