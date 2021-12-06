int main(void) {
    const int* p;
    p = new int(4);
    //*p = 7; // this is not allowed!
    p = new int(5); // this is allowed
    //We cannot change the value pointed to by pointer p.
}

/*
 ptr_to_const.cpp:4:8: error: read-only variable is not assignable
    *p = 7; // this is not allowed!
    ~~ ^
1 error generated.
*/

