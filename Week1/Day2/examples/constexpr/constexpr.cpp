#include <stdlib.h>

int getRandomNo(){
    return rand() % 10;
}

int main() {
    const int varB = getRandomNo();      // OK
    //constexpr int varC = getRandomNo();  // not OK! compilation error
    return 0;
}

