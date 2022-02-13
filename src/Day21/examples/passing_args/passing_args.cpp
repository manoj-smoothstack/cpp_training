#include <cassert>
#include <iostream>
#include <string>
#include <thread>

void f(int i, std::string const& s) {
    std::cout << s << std::endl;
}

void not_oops(int some_param) {
    char buffer[1024];
    sprintf(buffer,"%i", some_param);
    std::thread t(f, some_param, std::string(buffer));
    t.detach();
}	

int main(void) {
    not_oops(3);
}
