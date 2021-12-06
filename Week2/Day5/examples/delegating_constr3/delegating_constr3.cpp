#include <string>

using namespace std;

// The right way to do this:
class Person {
    private:
        string name;
        string email;
    private:
        Person() {};
    public:
        Person(string first, string last) {
            this->name = first + " " + last;
        };
        Person(string first, string last, string email) : Person(first, last) {
            this->email = email;
        };
        string getName() { return name; }
        string getEmail() { return email; }
};

// The Person(first, last) constructor is executed before the body of the 3 parameter constructor is executed.

int main(void) {
    Person p("John", "Galt", "john.galt@shrugged.com");
}
