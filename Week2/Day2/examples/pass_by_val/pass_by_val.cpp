#include <string>
#include <cassert>
using namespace std;
void pass1(int x) {
    x = 2;
}
void pass2(string s) {
    s = "World";
}
int main(void) {
    int x = 4;
    pass1(x);
    assert(x == 4);
    string s = "Hello";
    pass2(s);
    assert(s == "Hello");
}

//The parameters are copied. Only the copies are modified. The original is untouched. This applies to primitives and objects. But arrays are different. The elements of an array do not behave like members of an object.
