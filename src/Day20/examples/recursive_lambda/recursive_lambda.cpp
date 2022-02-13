#include <functional>
#include <cassert>

int main(void) {
    auto term = [](int a)->int {
        return a*a;
    };
    auto next = [](int a)->int {
       return ++a;
    };

    std::function<int(int,int)> sum;
    sum = [term, next, &sum](int a, int b)->int {
        if (a > b)
            return 0;
        else
            return term(a) + sum(next(a), b);
    };

    assert(sum(1,10) == 385);
}

