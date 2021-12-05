#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main(void) {
    vector<string> v;
    v.push_back("Hell");
    v.push_back("World");
    v.at(0) = "Hello";
    assert(v.at(0) == "Hello");
}
