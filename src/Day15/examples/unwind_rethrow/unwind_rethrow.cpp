#include <sstream>
#include <cassert>
#include <cstring>
std::stringstream seq;
void level3() {
    throw std::runtime_error("error");
}
void level2() {
    try {
        level3();
    } catch(...) {
        seq << "level2";
        throw;
    }
}
void level1() {
    try {
        level2();
    } catch(...) {
        seq << "level1";
        throw;
    }
}
int main () {
    try {
        level1();
    } catch (const std::exception& e) {
        assert(!strcmp(e.what(), "error"));
    }
    assert(seq.str() == "level2level1");
}

