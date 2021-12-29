//Clear strings before you use them.
#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
    char srcstr[2];
    srcstr[0] = 'H';
    // cout << srcstr << endl; // this can crash your program
    srcstr[1] = '\0';
    char deststr[2];
    strcpy(deststr, srcstr);
    if (!strcmp(deststr, srcstr)) {
        cout << "The two strings are equal!" << endl;
    }
}
