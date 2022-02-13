#include <cassert>
#include <cstddef>

int main(void) {
    struct Name {
        long id;
        int : 32;
        char c;
    };

    assert(offsetof(Name, id) == 0);
    assert(offsetof(Name, c) == 12);
}
