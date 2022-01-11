#include <cstdlib>

int main(void) {
    char* c = (char*)malloc(10);
    delete c;
}
