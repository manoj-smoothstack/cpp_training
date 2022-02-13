#include <cassert>
#include <cmath>
#include <string>

using namespace std;

class Quadrilateral {
    public:
        double sidea,sideb,sidec,sided,theta1,theta2,side,theta;
        const double PI = 3.14159265;
        inline static string called;
        Quadrilateral(double sidea, double sideb, double sidec, double sided, double theta1, double theta2) : 
sidea(sidea), sideb(sideb), sidec(sidec), sided(sided), theta1(theta1), theta2(theta2) {
            this->side = (sidea+sideb+sidec+sided)/2;
            this->theta = theta1 + theta2;
        };
        Quadrilateral& operator=(const Quadrilateral& other) {
            if (this == &other) return *this;
            this->sidea = other.sidea;
            this->sideb = other.sideb;
            this->sidec = other.sidec;
            this->sided = other.sided;
            this->side = other.side;
            this->theta1 = other.theta1;
            this->theta2 = other.theta2;
            this->theta = other.theta;
            return *this;
        }
        virtual double area() {
            called = "Quadrilateral";
            return sqrt((side-sidea)*(side-sideb)*(side-sidec)*(side-sided) - 
(sidea*sideb*sidec*sided)*pow(cos(theta*PI/(2*180)),2));
        };
        double perimeter() { return sidea+sideb+sidec+sided; };
};

class Rectangle : public Quadrilateral {
    public:
        double length, width;
        Rectangle(double length, double  width) : Quadrilateral(length, width, length, width, 90, 90) {
            this->length = length;
            this->width = width;
        };
        Rectangle& operator=(const Rectangle& other) {
            this->Quadrilateral::operator=(other);
            if (this == &other) return *this;
            this->length = other.length;
            this->width = other.width;
            return *this;
        }
        virtual double area() { called = "Rectangle"; return length*width; };
};

int main(void) {
    Rectangle r(4, 4);
    Quadrilateral q(4, 4, 4, 4, 90, 90);
    q = r; // note: copy assignment operator of 'Quadrilateral' is implicitly deleted because field 'PI' is of const-qualified type 'const double' 
    q.area();
    assert(Quadrilateral::called == "Quadrilateral");
    Quadrilateral* q1 = &r; // pointer does not do the copy assignment
    q1->area();
    assert(Quadrilateral::called == "Rectangle");
    Quadrilateral q2 = *q1; // dereferencing does not preserve memory, no assignment operator called, but implicitly defined copy constructor of Quadrilateral is called
    q2.area();
    assert(Quadrilateral::called == "Quadrilateral");
}
