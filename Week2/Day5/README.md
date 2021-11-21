# Assignments

## 1. Static and Singleton(ish)
Create a Person class that returns an instance of a unique Person, which is unique based
on name. If the Person already exists, then it delete the Person pointer and returns a new Pointer
to the Person. At the end of the program, the count field must be incremented in such as way
if two persons with the same name are found, then count is two for that Person name.

For example, let's say the names are:

{"bob", "james", "janet", "bob", "stella"};

Then the answer should look like:

bob: 1, james : 1, janet : 1, bob: 1, stella : 1}

There should be only one Person pointer for Bob, but it's count must be 2 (1+1).

You are not allowed to increment the count in the getPerson() method, nor in the main program.
You are also not allowed to write any methods. However, you can implement constructors and 
destructors as you wish.


class Person {
    private:
        int index;

    public:
        string name;
        int count;
        static Person* persons[10];
        static Person* getPerson(string name) {
            return nullptr;
        }
};

int main(void) {
    // declare and string array of names here
    
    for (int ii = 0; ii < 5; ii++) {
        // fetch the name and print the result
    }
}
