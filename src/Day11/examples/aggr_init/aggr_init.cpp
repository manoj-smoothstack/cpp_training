#include <cassert>
  
int main(void) {
    int x[3] = {1, 2, 3};
    struct {int i; char c;} y = {3, 'd'};
    assert(y.c == 'd');
    class F {
        public:
            int f;
            F(int f) {this->f = f;};
    } f = {1};
    assert(f.f == 1);
}

// Aggregate initialization initializes aggregates.

