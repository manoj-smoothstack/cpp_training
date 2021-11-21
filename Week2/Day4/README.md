# Assignments

## 1. rvalue references
Write a class which implements Grade with 4 possible scores.

Score = 10: Grade D
Score = 20: Grade C
Score = 30: Grade B
Score = 10: Grade A

class Grade {
    // < add if necessary >
    public:
        char grade(const int&& score) {
            // cannot use if, case and for loops
            return 'C';  // hardcoded fix this
        }
};


int main(void) {
    /*
        Generate an error with N=4 values eg. {10, 30, 20, 20}
        Write a loop that loops through the array, and calls the method above.
        You are not allowed to use any if/else statements.
        You print the result of the method using cout.
    */
    return 0;
}


## 2. merge sort
Implement a merge sort class, that uses a comparator method as a member function pointers.
You can sort Students by their scores in range ([1..100]);
You should use recursion, but hide it in a private method. The entry point sort() method should
not call itself.

struct Student {
    string studentId; // studentId is unique
    int score; // between [1..100]
    bool comparator(Student x, Student y); // returns true if score of x is less than score of y
}

class MergeSort {
    public:
        void sort(vector<Student>& students) {};  // don't use recursion directly here!
}
