//If you used strncpy, you may mask out null termination issues, as strncpy copies n characters and does not rely on a null terminated string to stop the copy.
#include <cassert>
#include <string.h>
#include <iostream>

using namespace std;

int main(void) {
    char srcstr[32];
    //memset(srcstr, '\0', 32); // this will not be required
    strcpy(srcstr, "Hello World");
    char deststr[32];
    //memset(deststr, '\0', 32);
    strncpy(deststr, srcstr, 5);
    assert(!strncmp(deststr, "Hello", 5));
}
