#include <cassert>

class Multiplier {
public:
    Multiplier(int m): multiplier(m) {}
    int operator()(int x) { return multiplier * x; }
private:
    int multiplier; // initialized by constructor initialization
};

int main(void) {
    Multiplier m(5); // involves Multiplier constructor
    assert(m(4) == 20); // invokes operator()
}

