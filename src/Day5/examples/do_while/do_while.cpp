#include <iostream>

int main() {
    int j = 2;
    do { // compound statement is the loop body
        j += 2;
        std::cout << j << " ";
    } while (j < 9);
    std::cout << '\n';
}   
