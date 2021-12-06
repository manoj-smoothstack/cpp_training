#include <string>
#include <set>
#include <iostream>

using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {};
    int getAge() const { return age; };
    string getName() const { return name; };
};


struct CustomCompare {
    bool operator()(const Person& lhs, const Person& rhs) const {
        return lhs.getAge() < rhs.getAge();
    }
};

int main(void) {
    set<Person,CustomCompare> setOfPersons;
    setOfPersons.insert(Person("Person 1", 25));
    setOfPersons.insert(Person("Person 2", 16));
    setOfPersons.insert(Person("Person 3", 28));
    setOfPersons.insert(Person("Person 4", 9));
    for(set<Person,CustomCompare>::iterator it = setOfPersons.begin(); it!=setOfPersons.end(); ++it) {
        cout << it->getName() << " , age : " << it->getAge()<< endl;
    }
}
