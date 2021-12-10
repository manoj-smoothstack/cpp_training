#include <cassert>

void fun(int* ptr) {
    *ptr += 10;
}

int main(void) {
    const int val = 10;
    const int *ptr = &val; // pointer to const int
    int *ptr1 = const_cast<int *>(ptr); // create a compatible pointer
    fun(ptr1); // we are able to call the existing function
    assert(val == 10); // original value does not change
    //fun(ptr); // error: no matching function for call to 'fun'
    int val2 = 5; // val2 is not a const
    int* ptr2 = &val2; // we have pointer to non-const in
    fun(ptr2); // we change the value by dereferencing
    assert(val2 == 15); // we are able to change the value
    return 0;
}

