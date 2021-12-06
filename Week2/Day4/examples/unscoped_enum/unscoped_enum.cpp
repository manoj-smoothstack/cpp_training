#include <cassert>
  
enum Color { red, green, blue };
//enum MyColor { red, yellow, pink }; // conflict!
namespace Pixels { enum MyColor {green, red, pink}; };

int main(void) {
    Color r = red;
    assert(r == 0 && blue == 2);
    assert(Pixels::red == 1);
    assert(Pixels::red + Pixels::pink == 3);
    //Pixels::MyColor *mycolor =  &Pixels::red; // error: cannot take the address of an rvalue of type 'Pixels::MyColor'
    assert(Pixels::red + green == 2);
}
