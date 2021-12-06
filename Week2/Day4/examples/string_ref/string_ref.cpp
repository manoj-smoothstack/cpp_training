#include <string>
#include <cassert>

using namespace std;

int main(void) {
    string s = "hello";
    string *s1 = &s;
    s = "world"; // did not change it's address
    assert(s1 == &s);
}

//Note that reinitializing s does not change it's address.

