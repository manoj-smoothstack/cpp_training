#include <string>

using namespace std;

//Constructor delegation can be used when there is overlapping functionality between constructors, and you do not want to duplicate logic, as that could turn into a maintenance issue. Consider this scenario:
class Person {
    private:
        string name;
        string email;
    private:
        Person() {};
    public:
        Person(string first, string last) {
            this->name = first + " " + last; // duplicate logic
        };
        Person(string first, string last, string email) {
            this->name = first + " " + last;
            this->email = email;
        };
        string getName() { return name; }
        string getEmail() { return email; }
};

//Where there is one line of duplicate logic between the two Person constructors.

int main(void) {
    Person person("John", "Galt", "john.galt@shrugged.com");
}
