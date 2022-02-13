#include <cassert>
  
void func(float succeeds, float fails) {
    assert(succeeds == 3); // not very surprised, should I be?
    assert(fails != 3.1); // why does this fail?
}

int main(void) {
    func(3, 3.1);
}
