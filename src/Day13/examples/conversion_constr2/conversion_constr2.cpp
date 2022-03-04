/*
 * The function can't use this value directly, but because there's a conversion from the type of the argument—double—to the type of the matching parameter—Money—a temporary value of type Money is constructed from the argument and used to complete the function call.

In the third call to display_balance, notice that the argument is not a double, but is instead a float with a value of 9.99—and yet the function call can still be completed because the compiler can perform a standard conversion—in this case, from float to double—and then perform the user-defined conversion from double to Money to complete the necessary conversion.
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

