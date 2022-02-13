#include <cassert>

int main(void) {
    int s1 = 10;
    int s2 = 20;
    int s4 = s1 + s2;
    int& s3 = s4; 
    assert(++s3 == 31);
}

