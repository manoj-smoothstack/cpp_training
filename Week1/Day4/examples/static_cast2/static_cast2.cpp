//You can use a static_cast against a user defined operator on your class.

#include <cassert>
#include <string>
using namespace std;

class MyInt {
private:
    int x;
public:
    MyInt(int x_in = 0) : x{ x_in } { }
    operator string() { return to_string(x); }
};

int main() {
    MyInt myint(3);
    string str = static_cast<string>(myint);
    assert(str == "3");
}

