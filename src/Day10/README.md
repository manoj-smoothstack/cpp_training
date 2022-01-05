# Assignments

## 1. Static and Singleton(ish)

Traditionally a Singleton class only should be 1 instance. Here it's 1 instance per name,
as opposed to one instance per person. Hence we call it Singleton(ish).
It's also a Factory(ish) pattern as we are creating instances of a Person from the Person
class. But it's not a full-blown factory like the factory pattern, and there is quite a divergence
from it, as traditional Factory patterns take a type as input, and create an instance from it.

Create a Person class that returns an instance of a unique Person, which is unique based
on name. If the Person already exists, then it delete(s) the Person pointer and returns a new Pointer
to the Person. At the end of the program, the count field must be incremented in such as way
if two persons with the same name are found, then count is two for that Person name.

For example, let's say the names are:

```
{"bob", "james", "janet", "bob", "stella"};
```

Then the answer should look like:

```
bob: 1, james : 1, janet : 1, bob: 1, stella : 1}
```

There should be only one Person pointer for Bob, but it's count must be 2 (1+1).

You are not allowed to increment the count in the getPerson() method, nor in the main program.
You are also not allowed to write any methods. However, you can implement constructors and 
destructors as you wish.


```
class Person {
    private:
        int index;
        static Person* persons[10];
        // add your constructors/destructors
    public:
        // add your constructors/destructors
        string name;
        int count;
        static Person* getPerson(string name) { // modify this method
            return nullptr; // for now returns a null
        }
};

int main(void) {
    // declare and string array of names here
    
    for (int ii = 0; ii < 5; ii++) {
        // fetch the name and print the result
    }
}
```
