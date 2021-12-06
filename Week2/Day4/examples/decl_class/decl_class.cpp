//Example class declaration:
#include <cassert>
#include <string>

using namespace std;

class Person {
    private: // private members cannot be accessed from outside the class
        string name; // private member variable
    public:
        Person(string first, string last) {  // a public constructor
            this->name = first + " " + last;  // "this" allows us to access a pointer to this class
        };
        string getName() { return name; } // a public accessor method
};

int main(void) {
    Person p("John", "Galt");
    assert(p.getName() == "John Galt");
}
