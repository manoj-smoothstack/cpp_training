#include <cassert>
  
class Rectangle {
    private:
        float width;
        float height;
    public:
        Rectangle(float width, float height) : width(width), height(height) {};
        float area() { return width*height; };
        float perimeter() { return 2*(width+height); };
};

class Square : public Rectangle {
    public:
        Square(float size) : Rectangle(size, size) {};
};

int main(void) {
    Rectangle r(4, 4);
    Square s(4);
    assert(s.area() == r.area());
}
