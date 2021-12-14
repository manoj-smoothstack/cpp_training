#include <string>
#include <cassert>
#include <cstring>

int main(void) {
    std::string s1 = "hello";
    char s2[6];
    s2[5] = 0;
    strcpy(s2, "hello");    
    assert(s1 == s2);
}

