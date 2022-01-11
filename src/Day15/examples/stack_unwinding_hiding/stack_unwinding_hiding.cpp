#include <sstream>
#include <cassert>
#include <cstring>
std::stringstream seq;
void level3() {
    throw "error";
}
void level2() {
    try {
        level3();
    } catch(...) {
        seq << "level2";
    }
}
void level1() {
    try {
        level2();
    } catch(...) {
        seq << "level1";
    }
}
int main () {
       level1();
       assert(seq.str() == "level2");
}

