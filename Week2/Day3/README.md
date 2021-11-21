# Assignment

## 1. Method pointers
Write a function that takes 3 parameters as input:

int compute(int arg1, int arg2, unsigned char funcmask);

where arg1 and arg2 are operands in a simple expresison of the type:

arg1 <operator> arg2

Support 3 operators as regular functions:

add() (+)
subtract() (-)
multiply() (*)

And these functions are dynamically called through a function pointer depending upon which of the first 3 bits in the funcmask is set. 

So for instance:

0000 0001 --> add()
0000 0010 --> subtract()
0000 0100 --> multiply()

Store these function pointers in an array which is a global variable available to the compute() function.
Check the bit in funcmask, and associate a function to be called from the array.

The compute() function then returns the result of the function called through pointer.
