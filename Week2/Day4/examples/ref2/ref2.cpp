//References cannot be const qualified.
int main(void) {
    char c = 'b';
    //char &const p = c; // ref_const.cpp:6:11: error: 'const' qualifier may not be applied to a reference
    //const char& q = c; // ref_const.cpp:6:11: error: 'const' qualifier may not be applied to a reference
    //p = 'p';
}

/*
 ref2.cpp:4:11: error: 'const' qualifier may not be applied to a reference
    char &const p = c; // ref_const.cpp:6:11: error: 'const' qualifier may not be applied to a reference
          ^
1 error generated.
make: *** [Makefile:32: ref2.o] Error 1
*/
