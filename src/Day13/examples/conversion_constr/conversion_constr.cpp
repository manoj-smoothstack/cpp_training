/*
 * Conversion constructors define conversions from user-defined or built-in types to a user-defined type.
This example demonstrates a conversion constructor that converts from the built-in type double to a user-defined type Money.

Notice that the first call to the function display_balance, which takes an argument of type Money, doesn't require a conversion because its argument is the correct type.

However, on the second call to display_balance, a conversion is needed because the type of the argument, a double with a value of 49.95, is not what the function expects.
*/

#include <iostream>

class Money {
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance) {
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[]) {
    Money payable{ 79.99 };

    display_balance(payable);
    display_balance(49.95);
    display_balance(9.99f);

    return 0;
}

