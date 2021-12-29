#include <string>

using namespace std;

// This does not really work.

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
        Person(string first, string last, string email) {
            this->email = email;
            Person(first, last); // This is rvalue temporary and does nothing
        };
        string getName() { return name; }
        string getEmail() { return email; }
};

int main(void) {
    Person person("John", "Galt");
}
