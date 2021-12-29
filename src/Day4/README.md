# Assignments

## 1. Arithmetic expressions
Exercise: Which of the following expressions will fail at runtime? Why? Why not?

```
#include <iostream>
#include <cassert>

using namespace std;

int main(void) {
    assert(3 == 3.0);
    float x = 3.1;
    assert(x == 3.1);
    assert(3.1 == 3.1);
    assert(true == 1.0);
    assert('a' == 97);
    int* p = 0;
    assert(NULL == p);
    assert(NULL == 0);
}
```


## 2. Truth table for cast operators
Exercise: Generate a truth table for cast operators, when arithmetic operations are performed between two variables. For example int + float gives a float. Consider the types: int, float, char, bool

## 3. Operators
Exercise: List the binary, unary and ternary operators with examples

## 4. Increment Operators
Exercise: Will below program work with no errors? Why?

```
 #include <cassert>
  
 int main(void) {
    int x = 4;
    int y = x+++2;

    assert(y == 6);
    assert(x == 5);
 }
```

What is the order of precedence of operators above when y is initialized to x+++2?

## 5. More truth tables
Implement the truth table for AND, OR and NOT logical operators.
