# Assignment

## 1. Fibonacci series and recursion
Write a program to generate an array of 50 Fibonacci terms of type int recursively.
What problems did you encounter while computing this? At what point? How do you detect
the problem? Does your compute give an error?

Note: You must use recursion to solve this problem.

## 2. Integer overflow
2. Given a b-bit int (for int32, b = 31), how would you determine the index of the largest
Fibonacci term that you can fit in int32? Solve this without brute computing the Fibonacci series
above. Verify your answer for a long.

Note: The Fibonacci series goes 1, 1, 2, 3, 5, 8, 21,...... So 5 is the index for 8.

Hint: There is a closed-form expression for the n-th Fibonacci number, Binet's formula,

F(n) = (phi^n - psi^n) / (phi - psi)

where

phi = (1 + 5^0.5)/2 and psi = (1-phi) = -1/phi
