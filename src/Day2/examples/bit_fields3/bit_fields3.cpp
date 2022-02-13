#include <cassert>
int a;
const int b = 0;
struct S {
    // simple cases
    int x1 : 8 = 42;                 // OK; "= 42" is brace-or-equal-initializer
    int x2 : 8 { 42 };               // OK; "{ 42 }" is brace-or-equal-initializer
    // ambiguities
    int y1 : true ? 8 : a = 42;      // OK; brace-or-equal-initializer is absent
    int y3 : (true ? 8 : b) = 42;    // OK; "= 42" is brace-or-equal-initializer
    int z : 1 || new int { 0 };      // OK; brace-or-equal-initializer is absent
};

struct S1 { int x1 : 8 = 42; };
struct S2 { int x2 : 8 { 42 }; };
struct S3 { int y1 : true ? 8 : a = 42; };
struct S4 { int y3 : (true ? 8 : b) = 42; };
struct S5 { int z : 1 || new int { 0 }; };

int main(void) {
    assert(sizeof(S) == 8);
    assert(sizeof(S1) == 4);
    assert(sizeof(S2) == 4);
    assert(sizeof(S3) == 4);
    assert(sizeof(S4) == 4);
    assert(sizeof(S5) == 4);
}

//In case of ambiguity between the size of the bit field and the default member initializer, the longest sequence of tokens that forms a valid size is chosen.

