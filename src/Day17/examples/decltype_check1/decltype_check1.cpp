#include <type_traits>
#include <cassert>
 
struct A { double x; };
const A* a;

int main(void) {
    decltype(a->x) y;       // type of y is double (declared type)
    static_assert(std::is_same_v<decltype(y), double>);
    
    //decltype((a->x)) y1; // error: declaration of reference variable 'y1' requires an initializer

    decltype((a->x)) z = y; // type of z is const double& (lvalue expression)
    static_assert(std::is_same_v<decltype(z), const double&>);

    decltype(a->x) z1 = y; // notice we have no brackets around a->x
    static_assert(std::is_same_v<decltype(z1), double>); // it's not a reference anymore
}

