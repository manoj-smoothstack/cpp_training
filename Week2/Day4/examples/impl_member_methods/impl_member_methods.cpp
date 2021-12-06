#include <cassert>
#include <string>

using namespace std;

class Person {
    private:
        string name;
    public:
        Person(string first, string last) {
            this->name = first + " " + last;
        };
        string getName() { return name; }
};

int main(void) {
    Person p("John", "Galt"); // creating objects
    assert(p.getName() == "John Galt");
}

//getName() is a member method.

