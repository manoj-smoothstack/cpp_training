#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <iostream>

void f() { // potentially-throwing
    int rr;
    srand(time(NULL));
    rr = rand() % 10 + 1; // random number between 1 and 10
    rr > 5 ? throw 55 : rr;
}
void g() noexcept {
    f();      // valid, even if f throws
}
int main(void) {
    try {
        g();
    } catch(...) {
        std::cout << "main error" << std::endl; // never called, but that's the point!
    }
}

