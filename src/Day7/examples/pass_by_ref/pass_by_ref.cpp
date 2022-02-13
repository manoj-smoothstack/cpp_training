//Every parameter is passed by value unless it is passed by reference. To pass by reference, the & is used on the receiving side.
#include <cassert>

void pass_by_ref(int& x) {
    x = 7;
}

int main(void) {
    int y = 4;
    pass_by_ref(y);
    assert(y == 7);
}

//References help make the code look cleaner.
