#include <cassert>
#include <cstdint>

union S {
    std::int32_t n;     // occupies 4 bytes
    std::uint16_t s;    // occupies 2 bytes
    std::uint8_t c;     // occupies 1 byte
};                      // the whole union occupies 4 bytes

int main() {
    S s = {10}; // initializes the first member, s.n is now the active member
    // at this point, reading from s.s or s.c is undefined behavior
    assert(s.n == 10);
    s.s = 5; // s.s is now the active member
    assert(s.s == 5);
}
