
typedef int myint;

void myoverload(myint x) {}

//void myoverload(int x) {} // error: redefinition of 'myoverload'

int main(void) {
    myoverload(myint(2));
}
