# Assignments

## 1. Float precision
Write a program that takes as input a fraction, and prints the internally stored approximate floating point number along with J and N where:

Approx ~= J/2**N

So for instance if the user enters the number 0.125, your program responds with:

J = 450828337098296, N = 55
0.125129999999999963478103381930850446224212646484375

## 2. Calling const and non-const functions

Create a simple struct of two functions, one const and the other non const. Write a main that shows
two calls, one should invoke the const function and other should invoke the non const function.

The two functions should have the following signature:

void myfunc(float f);
void myfunc(float f) const;
