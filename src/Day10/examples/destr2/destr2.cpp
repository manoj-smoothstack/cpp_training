#include <cassert>

/*
Exercise
Are the destructors called? (Yes)
Will this program fail? (No)
When do the destructors get called? (1)
Which destructors are called? (2)
How many total destructors are called? (11)
Why do we need to have a destructor?
Why do we need to delete the students?
*/
class Student {
    public:
        inline static int numDeleted;
        ~Student() { // (2)
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
        ~Classroom() { // (2)
            delete [] students;
        }
        Student* getStudents() {
            return students;
        }
};

int main(void) {
    int numStudents = 10;
    {Classroom classroom(numStudents);} // (1)
    assert(Student::numDeleted == numStudents);
}
