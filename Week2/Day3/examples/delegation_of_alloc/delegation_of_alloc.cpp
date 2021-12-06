#include <cassert>
#include <string.h>
#include <iostream>
using namespace std;

void get_clean_str(char** str, int size) {
    char* mystr = new char[size](); // instead of memset!
    *str = mystr;
}

int main(void) {
    char** cleanstr = new char*[1]; // this is cumbersome and not self-contained
    get_clean_str(cleanstr, 32);
    strcpy(*cleanstr, "Hello");
    assert(!strcmp(*cleanstr, "Hello"));
}
