/*
If Musician and Teacher inherit from Person virtually using the virtual keyword, it allows us to solve the problem of multiple inheritance. 
As far as possible multiple inheritance is not recommended unless it's the only option.
*/

#include <string>
using namespace std;
class Person {
    public:
        string name;

};
class Musician : virtual public Person {
    public:
        string instrument;
};
class Teacher : virtual public Person {
    public:
        string school;
};
class MusicTeacher: public Musician, public Teacher {};

int main(void) {
    MusicTeacher mt;
    mt.name = "Al Di Meola";
}


