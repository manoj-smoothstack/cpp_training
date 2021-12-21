# Practice Assignment

## Long Multiplication in C++

1. Write code that takes as input two numbers using iostream and computes their multiplication using the traditional long multiplication method:

```
     124
   x 456
   -----
     744
    6200
   49600
  ------
   56544
```

Implement a class called BigNumber with constructor that takes as input a long int. The constructor should call the set() method
to initialize the number. 

Implement a multiply() method that takes as input a BigNumber object and computes the output BigNumber object.

Assume two instances A and B of type BigNumber. Implement the equivalent of A\*B using the multiply()
method. You do not need to overload the "\*" operator for this class. The result of multiply should be stored in the output 
object which is passed by reference to the multiply method.

You should implement the following constructors and public methods:

```
BigNumber(long);
void multiply(const BigNumber& input, BigNumber& output);
long number() const;
void set(long);
```

The number() method returns the long int stored privately inside BigNumber.

The set() method sets a long int number and stores it inside BigNumber. The multiply() method should use the set() method
to update the output reference.

2. Write test methods to validate your result using regular multiplication operator "\*". Implement these tests using
google test package. In your makefile, add a test target that allows you to run the tests.

3. When would the long multiplication be useful to use in place of the regular multiplication? Demonstrate this with an
example. 

4. Modify BigNumber to add a new constructor that takes a std::string argument as input, and tests
if you would have an overflow if this argument is converted to long (typically 64 bit). If there is no overflow
then you should store it natively as long. If there is overflow, then you store it as unsigned char[64] array. So you may need to use a union to 
manage this storage.

The overflow detection will be checked by the multiply() method to detect an overflow after multiplication has occurred.
The multiply() method also calls the appropriate set() method.

So your new public prototypes will look like following:

```
class BigNumber {
private:
   bool overflow;
   union {
       long lnum;
       unsigned char cnum[64];
   } actualUnion;

public:
    BigNumber(long);
    BigNumber(std::string);
    BigNumber multiply(const BigNumber&) const;
    std::string number() const;
    void set(long);
    void set(std::string);
}
```

The overflow flag will help you determine which member of the union is currently active. Note that if the user sends in 
character arrays longer than 64 bytes, you may have to perform appropriate error checking.

Note that number() now returns std::string irrespective of, if there is an overflow or not.

You can add a new set() method that takes an std::string as input.

4. Implement a simulate_multiply() method that simulates multiplication. It will return a vector to represent:

```
     124
   x 456
   -----
     744
    6200
   49600
  ------
   56544
```

Your simulate_multiply() method must use std::vector.

```
vector<vector<unsigned char>> simulate_multiply();
```

Please show how you can use a typedef in place of vector<vector<unsigned char>> above.
Call it numvec.

The first row of the vector in this case would have three elements '1', '2', '3'.
The second row of the vector would have 3 elements '4', '5', '6'.
The third row of the vector would have 3 elements '7', '4', '4'.
The fourth row of the vector would have 3 elements '6', '2', '0'.
The fifth row of the vector would have 3 elements '4', '9', '6'.
The sixth row of the vector would have 5 elements '5', '6', '5', '4', '4'.

5. Implement a print() method that that prints the simulation. It will take the vector from above step as input, and
print the output as below:

```
     124
   x 456
   -----
     744
    6200
   49600
  ------
   56544
```

Note the left justification and the padded zeroes along with the hyphenated lines and the "x" or multiply operator followed
by a space character that need to be part of the print output exactly as shown.

Your print() method should be declared as:

```
void print(numvec myvec) const;
```


6. Modify the BigNumber class to handle variable logic that detects overflow. If you detect an overflow with regular "\*"
operator, then you resort to use the long multiplication, otherwise you use the regular "\*" multiplication. The user is
transparent to this functionality. They send in numbers, big or small, but you will need to use variable logic to determine
which form of multiplication you need to use. Always prefer the "\*" multiplication over the long multiplication whenever it
is feasible. Note that instances A and B may be small numbers to fit in a long int, but A\*B may not fit in a long int.
So when you write the detection logic for overflow, you will need to write code that predicts an overflow without performing
the actual multiplication. This way you can avoid the actual "\*" multiplication before you try a long multiplication, hence
avoiding two separate multiplications.


## Implement a Calendar class

1. Implement a C++ program that works like the cal command on unix.

```
cal 12 2021
```

```
    December 2021   
Su Mo Tu We Th Fr Sa
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31   
```

The program will support input argument for the calendar month and year that you need to parse. For now only implement
the option "MM YYYY". Other permutations are not necessary.

You will implement a Calendar class that has at least three public methods, and a constructor.

```
Calendar(int month, int year);
int\*\* get() const;
void print() const;
void set(int month, int year);
```

The constructor should initialize the parameter and call the set() method to generate a calendar based on the parameters.
The calendar can be stored as 2-dim array with 7 columns and a variable number of rows. Append an extra row which is a nullptr.
So in the case of Dec 2021, you would have 6 rows, with the 6th row being a int\* pointer that is a nullptr.

The get() method should simply return the calendar as a \*\* pointer. Since the last row is a nullptr, the caller of the
get() method should know the size of the dynamic array.

Please do not use a std::vector or std::array object to implement this. You must use plain-old arrays.

The print() method should print the output as shown above. Use the C++ enum wherever necessary to handle the months and weekdays.
For instance you will need to use 2 different enums:

- Month 
- Weekday

You will also need to use a statically initialized array to store number of days in each month.

Your program should use the time function only once to compute the day of the first of the month and then implement
regular flow control loops to implement the rest of the month. So for instance, in above example, you use the unix time
function only once to compute that Dec 1, 2021 is a Wednesday. Once you do that, you can compute the whole month yourself,
without using the time functions.

2. Write test functions to test your calendar class by comparing the output with unix time library functions.
Make sure you also perform appropriate validation for all input in addition to tests.

3. Verify your program for leap year logic, where February has 29 days.

4. Verify your program for year range. Does your calendar work for days before epoch? It does not have to, but if it does not
please explain why. If it does work, then please explain why it works.

5. Make sure you are handling all memory leaks.
