//Understanding C-style strings is a prerequisite for this course!
#include <stdio.h>
#include <string.h>

int main(void) {
    char mystr[32];
    memset(mystr, '\0', 32); // ensures null termination!
    strcpy(mystr, "Hello World!");
    printf("%s\n", mystr);
}

//All C-style strings must be null terminated.
//C-style strings are char arrays or char pointers.
