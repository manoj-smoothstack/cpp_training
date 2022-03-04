#include <cassert>

struct s {
    int& x;
};

int main(void) {
    int* dummy;
    assert(sizeof(struct s) == sizeof(dummy));
}

