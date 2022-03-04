#include <string.h>
#include <cassert>

int* badfunc() {
    int num = 256;
    int* tmp;
    tmp = &num;
    return tmp; // returning a pointer to stack variable!
}

int* goodfunc() {
    int *num = new int(256);
    return num;
}

int main() {
    int* x1 = goodfunc();
    assert(*x1 == 256);

    int* x = badfunc();
    char tmp[] = "hello world"; // additionally mess with stack
    int len = strlen(tmp);      // extra line of code
    assert(*x == 256);

    return 0;
}
