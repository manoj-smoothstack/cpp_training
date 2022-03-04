#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> myvec;
    myvec.push_back(2);
    myvec.push_back(7);
    assert(myvec.at(0) == 2);
}
