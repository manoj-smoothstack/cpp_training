# Assignments

## Using deep copy constructors and assignment operators.

Consider the following sentence:

```
"Quick brown fox jumps over the lazy dog."
```

Create a Sentence class with an std::vector<int> as a private member. The number of elements
in the vector depends upon the number of words in the sentence. The Sentence constructor should take in
a char\* pointer as input, and create a vector of ints. The int is the start offset of the word
in the original sentence char\* C style string.

Note you are not allowed to allocate separate C style strings for each word. You must use the int offset
to determine the boundaries. However, you are allowed to store one C style dynamic char\* pointer
as a private variable (char\* sentence as shown below), which stores the entire original sentence. 
The constructor needs to create a copy of the original char\* sentence passed to it, and not reuse 
the same char\* memory allocated by the caller of the constructor.

Here is an outline of your class (and is not necessarily the complete design):

```
class Sentence {
private:
    char* sentence;
    std::vector<int> vsentence; // stores the word offsets
public:
    Sentence(char* sent); // regular constructor
    // insert a deep copy  constructor here
    // insert a deep copy assignment operator here
    char* data(); // returns the data for sentence
    int num_words() const; // fetches the number of words 
    std::string get_word(int n); // get nth word in sentence 
    void replace(char* sent); // replace existing sentence
    ~Sentence(); // destroy any memory allocated
}
```

Write code demonstrates how to invoke the copy constructors and copy assignment operator
 in your code.

## Move constructor and move assignment operator

Implement move constructor and move assignment operator in previous assignment.
Write code that invokes the special functions.
