#include <cmath>
#include <cassert>

class scaled_sine {
public:
    explicit scaled_sine( float _m ) : m(_m) {}
    float operator()(float x) const { return sin(m*x); }
    float m;
};

template<typename T>
float evaluate_at( float x, const T& fn ) {
    return fn(x);
}

int main(void) {
    float f1 = evaluate_at(1.0, cos);
    assert(fabs(f1 - 0.540302) < 0.001);
    float f2 = evaluate_at(1.0, scaled_sine(3.0));
    assert(fabs(f2 - 0.14112) < 0.001);
}

