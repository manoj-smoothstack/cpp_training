#include <iostream>
#include <string>
#include <string_view>

std::string_view askForName() {
  std::cout << "What's your name?\n";

  // Use a std::string, because std::cin needs to modify it.
  std::string str{};
  std::cin >> str;

  // We're switching to std::string_view for demonstrative purposes only.
  // If you already have a std::string, there's no reason to switch to
  // a std::string_view.
  std::string_view view{ str };

  std::cout << "Hello " << view << '\n';

  return view;
} // str dies, and so does the string that str created.

int main() {
  std::string_view view{ askForName() };

  // view is observing a string that already died.
  std::cout << "Your name is " << view << '\n'; // Undefined behavior

  return 0;
}

