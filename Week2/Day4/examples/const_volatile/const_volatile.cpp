#include <cassert>

int main(void) {
    int some_val = 5;
    const int not_vol = some_val;
    assert(not_vol == some_val);
    //assert(some_val == 1); // compiler may substitute x for some_val
    const volatile int vol = some_val;
    assert(vol == 5); // compiler will not substitute vol for some_val here

    int new_val = 4;
    int *y = (int*)&not_vol; // 
    *y = new_val;
    assert(not_vol == new_val);

    y = (int*)&vol;
    *y = new_val;
    assert(vol == some_val);
}

