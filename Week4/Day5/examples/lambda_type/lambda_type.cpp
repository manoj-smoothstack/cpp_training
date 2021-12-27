#include <functional>
int main() {
    // A regular function pointer. Only works with an empty capture clause.
    double (*addNumbers1)(double, double) {
        [](double a, double b) {
          return (a + b);
        }
    };
    addNumbers1(1, 2);
    // Using std::function. The lambda could have a non-empty capture clause (Next lesson).
    std::function addNumbers2 { // note: pre-C++17, use std::function<double(double, double)> instead
        [](double a, double b) {
          return (a + b);
        }
    };
    addNumbers2(3, 4);
    // Using auto. Stores the lambda with its real type.
    auto addNumbers3 {
        [](double a, double b) {
            return (a + b);
        }
    };
    addNumbers3(5, 6);
}

