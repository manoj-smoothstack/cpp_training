# Assignments

## Class and Method Templating and Function Objects

Implement a template class called Account that should take two template parameters T and C:

- T as a base currency class type, and 
- C as a convert function object type

The Account class should have a private member called amt of type T.
The money for Account is always stored in base currency type T.

The Account class should have templated deposit() and withdraw() methods which take one templated argument 
each of type Q and actual argument which is the amount. This argument is the amount of money to 
deposit or withdraw to or from the internal amount, which is in currency type Q.

The amt member in Account needs to be kept updated depending upon calls to deposit() and withdraw().
The deposit() and withdraw() methods will also return the resultant balance amt as type T.

The deposit() and withdraw() functions call the function object C, to convert the input amount
in currency type Q to base currency type T. And then this converted amount in type T needs to be added
(deposit) or subtracted (withdraw) from/to the private member amt which is in base currency type T.

You will need to overload the function operator in Convert multiple times to
handle all permutations of currency conversions from source currency to destination
currency. Use approximate currency conversion market rate for this.

If the type Q is the same as type T, then you should not call Convert().

Also add a template member function in Account called currency() which takes a template
parameter R, and creates a new Account object in base currency type R with the equivalent amount
(after converting from currency T to currency R) and returns a pointer to that object.

Also add the following as templated special functions to the Account object:

- copy and move constructors
- copy and move assignment operators and 
- the comparison operators (==, <, >, <=, >=)
- arithmetic operators (+, -, ++, --)

The comparison operators should compare the respective private member amt based on the input
argument which is another Account object. Use the is_same() function to test if the Account<T>
types match before you compare them, if not then you should throw an exception.

The arithmetic operators should take an incoming templated argument X which can be any numeric
type, hence you need to check for numeric type using the std function.

Lastly you will need to develop specific classes to test your template. These are
one each for Dollar, Yen, Euro, and Pound. You will also need to test the comparison and arithmetic
operators with various numeric types such as float, int.
