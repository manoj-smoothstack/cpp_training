#include <string>
#include <utility>
#include <cassert>

template <typename T>
//T min_(T&& a, T &&b) {  // works but returns by value
//T& min_(T&& a, T &&b) { // does not work
    //return std::move(a < b? a: b); // error: non-const lvalue reference to type 'basic_string<...>' cannot bind to a temporary of type 'basic_string<...>'

//  error: no matching function for call to 'min_'
   // const std::string s = min_(std::string("A"), std::string("B"));
                         //^~~~
// rvalue_ref_func.cpp:9:5: note: candidate function [with T = std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>] not viable: expects an l-value for 1st argument
// T&& min_(T& a, T &&b) { // note that a is a lvalue reference and does not work
T&& min_(T&& a, T &&b) { // works best
    return std::move(a < b? a: b);  // rvalue expression
}

int main() {
   const std::string s = min_(std::string("A"), std::string("B"));
   assert(s == "A");
}

