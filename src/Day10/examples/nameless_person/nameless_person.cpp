#include <string>

//However, in this case you may not want a nameless Person object to be created. In such cases, you can make the constructor private.
class Person {
    private:
        std::string name;
        Person() {};
    public:
        Person(std::string first, std::string last) {
            this->name = first + " " + last;
        };
        std::string getName() { return name; }
};

//A nameless Person object can no longer be created.
//
int main(void) {
    //Person p; // can't do this
    Person p("Paul", "Gilbert");
}
