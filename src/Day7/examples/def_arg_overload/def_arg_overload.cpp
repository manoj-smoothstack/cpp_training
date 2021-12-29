
void myoverload(int x, int y = 4) {}
void myoverload(int x) {}

int main(void) {
    myoverload(2, 7);
    // myoverload(2);  // error: call to 'myoverload' is ambiguous
}

