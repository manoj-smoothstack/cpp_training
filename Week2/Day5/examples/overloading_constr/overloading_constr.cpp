#include <string>

using namespace std;

//What if you created a person object using other attributes such as email or age?
class Person {
    private:
        string name;
        string email;
    private:
        Person() {};
    public:
        Person(string first, string last) {
            this->name = first + " " + last; // email will remain nullptr
        };
        Person(string first, string last, string email) { // overload constructor
            this->name = first + " " + last;
            this->email = email;
        };
        string getName() { return name; }
        string getEmail() { return email; }
};

//This just means there are different ways to create an object instance. There is only one constructor that ever gets invoked in the life cycle of an object, and it is called only once at creation time.
//
int main(void) {
    Person p("Bob", "Marley", "bob.marley@reggae.com");
}
