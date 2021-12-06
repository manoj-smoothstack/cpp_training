#include <cassert>

int main(void) {
    int intarr[5] = { 16, 2, 77, 40, 12071 };
    int *myintptr = intarr;  // [] can be casted to *, implicitly
    assert(myintptr[2] == 77);

    int *intarr_pos = &intarr[1];
    intarr_pos++; // pointer arithmetic
    assert(*intarr_pos == 77);

    // One dimensional arrays on the heap
    int *intheapone = new int(2);  // Compiles, but that is not going to create 2 elements!
    int *intheaparr = new int[2];  // notice the square bracket
    intheaparr[0] = 4;
    intheaparr[1] = 7;
    assert(intheaparr[1] == 7);
    delete[] intheaparr;  // must delete memory for array using delete[] operator
    //delete[] intheaparr;  // free(): double free detected in tcache 2
}
