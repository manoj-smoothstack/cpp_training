#include <cassert>

struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 5 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    unsigned char b1 : 3;
    unsigned char :0; // start a new byte
    unsigned char b2 : 6;
    unsigned char b3 : 2;
};

int main() {
    assert(sizeof(S) == 2);
}

//The special unnamed bit field of size zero can be forced to break up padding. It specifies that the next bit field begins at the beginning of its allocation unit:

