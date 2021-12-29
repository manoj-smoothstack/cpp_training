#include <cassert>
#include <string>
using namespace std;
class Person {
    private:
        string name;
    public:
        Person(string first, string last) { // this is a constructor
            this->name = first + " " + last;
        };
        string getName() { return name; } // accessor method
};
int main(void) {
    Person p("John", "Galt"); // creating objects
    assert(p.getName() == "John Galt");
}

//The compiler adds a default constructor, if you did not add a constructor. The default constructor will be one with no parameters. 
