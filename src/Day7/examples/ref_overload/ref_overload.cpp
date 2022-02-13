#include <string>
#include <cassert>

static std::string called;

void myoverload(int x) {
    called = "int";
}

void myoverload(int& x) {
    called = "int&";
}

int main(void) {
    myoverload(5);
    assert(called == "int");
    const int &x = 7;
    myoverload(x);
    assert(called == "int"); // myoverload(int) is called!
}

