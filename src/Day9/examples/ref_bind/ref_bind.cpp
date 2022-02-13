#include <cassert>
#include <utility>

int& func() {
    int i3 = 7;
    //int& rrk = i3;
    //return rrk; //  warning: reference to stack memory associated with local variable 'i3' returned 
    int&& rrj = std::move(i3);
    return rrj;
}

int main(void) {
    int i2 = 42;
    int&& rri = std::move(i2); // binds directly to i2
    assert(i2 == 42);
    rri = 40;
    assert(i2 == 40);

    assert(func() == 7); // maybe useful in function calls
}
