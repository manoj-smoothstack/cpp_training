#include <cassert>

/*
Are the destructors called?
Will this program fail?
When do the destructors get called?
Which destructors are called?
When is the Classroom destructor called?
How many total destructors are called?
Why do we need to have a destructor?
Why do we need to delete the students?

*/
class Student {
    public:
        inline static int numDeleted;
        ~Student() {
            numDeleted++;
        }
};

class Classroom {
    private:
        Student* students;
    public:
        Classroom(int numStudents) {
            students = new Student[numStudents];
        }
        ~Classroom() {
            delete [] students;
        }
        Student* getStudents() {
            return students;
        }
};

int main(void) {
    int numStudents = 10;
    {Classroom classroom(numStudents);}
    assert(Student::numDeleted == numStudents);
}
