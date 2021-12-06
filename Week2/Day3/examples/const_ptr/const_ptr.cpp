#include <cassert>
  
int main(void) {
    const float* const p = new float(5);
    // p = new float(8); // error: cannot assign to variable 'p' with const-qualified type 'const float *const'
    // *p = 5; // error: read-only variable is not assignable
    float* const q = new float(2);
    // q = new float(3); // error: cannot assign to variable 'q' with const-qualified type 'float *const'
    *q = 7;
    assert(*q == 7);
}
