#include <string>
#include <iostream>

int main(void) {
    // Declaration and Assignment
    // Declaring a std::string object is simple:
    std::string my_str;
    
    // You can also initialize it with a C-string:
    std::string name("Phillip");
    
    // Or initialize it by copying another std::string object:
    std::string name2(name);
    // The memset like alternative:
    std::string filled(16, 'A');

    // Assigning values to a std::string is also simple, as you just need to use the = operator:

    // c-string assignment
    my_str = "Phillip";

    // Copy assignment
    my_str = filled;

    // Move assignment
    my_str = std::move(name2);

    // Comparing strings for equality using std::string, the  == operator has been overloaded for comparison:

    if (my_str == name2) {
        std::cout << "my_str and name2 match!" << std::endl;
    }

    // The use of the == operator works as long as one of the values is a std::string. This means we can compare the std::string to a string literal:
    if (my_str == "Phillip") {
        std::cout << "my_str and \"Phillip\" match!" << std::endl;
    }

    // You can also compare strings lexicographically using the other comparison operators:
    std::string s1 = "abc";
    std::string s2 = "abc ";
    if (s1 < s2) {
        std::cout << "s1" << " comes before " << s2 << " lexicographically" << std::endl;
    }

    // Concatenating Strings
    // Concatenation is also simple!
    my_str = "lip" + name2;
    my_str += "lip"; //C-string cat works too
}
