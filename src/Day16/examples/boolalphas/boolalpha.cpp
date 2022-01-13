#include <bits/stdc++.h>
#include <cassert>

int main(void) {
    std::stringstream ss;
    ss << std::boolalpha << true << 1 << -2 << 0;
    assert(ss.str() == "true1-20");
}

