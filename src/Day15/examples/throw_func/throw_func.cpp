/*
 * In this example we show an explicit throw of the invalid_argument object.
The catch behaves like a function and accepts the object by reference.
One can throw an exception in the try block directly.
Even the catch block can throw an exception but this is not recommended.
 */

#include <stdexcept>
#include <limits>
#include <iostream>
#include <string>
#include <cassert>

std::string err = "MyFunc argument too large.";

void MyFunc(int c) {
    if (c > std::numeric_limits< char> ::max())
        throw std::invalid_argument(err);
}

int main() {
    try {
        MyFunc(256); //cause an exception to throw
    } catch (std::invalid_argument& e) {
        assert(e.what() == err);
    }
    return 0;
}

