#include <cassert>
 
int main() {
    int a = 1, b = 1, c = 1; // a always passed by value == 1
 
    auto m1 = [a, &b, &c]() mutable { // a==1, b==2, c==2
        auto m2 = [a, b, &c]() mutable -> int { // a==1, b==2, c==3
            auto m = a + b + c;
            a = 4; b = 4; c = 4;
            return m;
        };
        a = 3; b = 3; c = 3; // c gets set to 3 (passed by ref)
        assert(m2() == 6);
    };
 
    a = 2; b = 2; c = 2;
 
    m1();   // calls m2() and returns 1+2+3
    assert(a == 2 && b == 3 && c == 4);
}

