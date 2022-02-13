/*
 * By declaring a conversion constructor to be explicit, it can only be used to perform direct initialization of an object or to perform an explicit cast.

This prevents functions that accept an argument of the class type from also implicitly accepting arguments of the conversion constructor's source type, and prevents the class type from being copy-initialized from a value of the source type.

This example demonstrates how to define an explicit conversion constructor, and the effect it has on what code is well-formed.

*/

#include <iostream>

class Money {
public:
    Money() : amount{ 0.0 } {};
    explicit Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance) {
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[]) {
    Money payable{ 79.99 };        // Legal: direct initialization is explicit.

    display_balance(payable);      // Legal: no conversion required
    //display_balance(49.95);        // Error: no suitable conversion exists to convert from double to Money.
    display_balance((Money)9.99f); // Legal: explicit cast to Money

    return 0;
}

