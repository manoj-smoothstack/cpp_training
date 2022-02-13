#include <sstream>
#include <cassert>
#include <cstring>

void level3() {
    throw std::runtime_error("error");
}

void level2() {
    level3();

}
void level1() {
    level2();
}

int main () {
    try {
        level1();
    } catch (const std::exception& e) {
        assert(!strcmp(e.what(), "error"));
    }
}

