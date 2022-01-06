/*
 * In this example, notice that you can still use the explicit conversion constructor to perform direct initialization of payable.
If instead you were to copy-initialize Money payable = 79.99;, it would be an error.
The first call to display_balance is unaffected because the argument is the correct type.
The second call to display_balance is an error, because the conversion constructor can't be used to perform implicit conversions.

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

