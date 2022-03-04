#include <cassert>
  
int main(void) {
    enum class Color { red, green = 20, blue };
    Color r = Color::blue;
    //int n = r; // error: cannot initialize a variable of type 'int' with an lvalue of type 'Color'
    int n = static_cast<int>(r);
    assert(n == 21);
    
    enum smallenum: short { a, b, c }; // enum that takes 16 bit ints
    enum class altitude: char {
        high = 'h',
        low = 'l'
    };
    altitude alt = altitude::high;
    assert(alt == altitude::high);
    char ch = 'h';
    assert(ch == static_cast<char>(altitude::high));
    
    enum { d, e, f = e + 2 }; // this can dirty the global namespace
    assert(f == 3);
    
    enum struct E11 { x, y };
    enum class E12 { x, y };
    //assert(E11::x == E12::x); //  error: invalid operands to binary expression ('E11' and 'E12')
}

