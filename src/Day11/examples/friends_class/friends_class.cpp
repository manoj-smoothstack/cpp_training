#include <iostream>
#include <sstream>

class MyClass {
     int i;
     friend std::ostream& operator<<(std::ostream& out, const MyClass& o);
     friend std::istream& operator>>(std::istream& in, MyClass& o);

     public:
         MyClass(int i = 0) : i(i) {}
};

std::ostream& operator<<(std::ostream& out, const MyClass& mc) {
    return out << mc.i;
}

std::istream& operator>>(std::istream& in, MyClass& mc) {
    return in >> mc.i;
}

int main() {
    MyClass mc(7);
    std::cout << mc << '\n';
    std::istringstream("100") >> mc;
    std::cout << mc << '\n';
}

// Here the friend function is indirectly called when the operator is invoked.

