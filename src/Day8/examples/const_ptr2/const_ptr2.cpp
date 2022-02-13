int main(void) {
    //const pointer
    int a = 4;
    int* const p = &a;
    int z = 10;
    //p = &z; // this is not allowed!

    //We cannot change pointer p, but can change the value pointed to by p.

}

/*
const_ptr2.cpp:6:7: error: cannot assign to variable 'p' with const-qualified type 'int *const'
    p = &z; // this is not allowed!
    ~ ^
const_ptr2.cpp:4:16: note: variable 'p' declared const here
    int* const p = &a;
    ~~~~~~~~~~~^~~~~~
1 error generated.
*/
