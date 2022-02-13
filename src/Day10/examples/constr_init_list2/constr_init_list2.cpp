#include <string>

using namespace std;

//Why use constructor intiliazation lists?

class Desk {
public:
    Desk(string name) {};
};

class Student {
private:
        Desk d;
        Desk getDesk(string name) {
            Desk* d = new Desk(name);
            return *d;
        }
public:
        Student(): d(getDesk("default")) {
        }
};

//We get improved performance. If getDesk() is the same type as d, then the construction of getDesk() happens inside d. The compiler does not make a separate copy of the object. Initializing d in the body of the constructor creates two copies. A temporary object is created which is then passed to the assignment operator in lvalue, where this is duplicated, then the temporary object is deleted upon hitting the ;
//
int main(void) {
    Student student;
}
