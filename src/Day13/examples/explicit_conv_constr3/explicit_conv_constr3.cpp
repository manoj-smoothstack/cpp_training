/*
 * The third call to display_balance is legal because of the explicit cast to Money, but notice that the compiler still helped complete the cast by inserting an implicit cast from float to double.
Although the convenience of allowing implicit conversions can be tempting, doing so can introduce hard-to-find bugs.
The rule of thumb is to make all conversion constructors explicit except when you're sure that you want a specific conversion to occur implicitly.

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

