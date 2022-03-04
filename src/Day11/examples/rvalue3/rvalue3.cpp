#include <cassert>

int main(void) {
    int s1 = 10;
    int s2 = 20;
    int&& s3 = s1 + s2;
    assert(++s3 == 31);
}

