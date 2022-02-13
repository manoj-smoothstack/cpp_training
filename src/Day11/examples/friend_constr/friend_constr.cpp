#include <cassert>

class Space {
public:
    Space(int, int, int);
    void testFriend();
};

class Point {
private:
    int x, y, z;
public:
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
    friend Space::Space(int, int, int);
};

Space::Space(int x, int y, int z) {
    Point p{x, y, z}; 
    assert(p.x == 2);
}

int main(void) {
    Space myspace{2, 4, 3};
}

