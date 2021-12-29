#include <cassert>
#include <string.h>
#include <iostream>
using namespace std;

void get_clean_str(char** str, int size) {
    char* mystr = new char[size]();
    *str = mystr;
}

void delete_clean_str(char** str) {
    delete *str; // we delete exactly what we allocate
}

int main(void) {
    char** cleanstr = new char*[1];
    get_clean_str(cleanstr, 32); // the main() allocates, the main() must delete
    strcpy(*cleanstr, "Hello");
    assert(!strcmp(*cleanstr, "Hello"));
    delete_clean_str(cleanstr); // with this design, chances are we will forget to call it
    delete [] cleanstr; // notice the array syntax
}
