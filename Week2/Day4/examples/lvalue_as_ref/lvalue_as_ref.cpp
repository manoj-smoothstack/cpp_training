//The below code is correct!
int global = 100;
int& setGlobal() {
    return global;
}
int main(void) {
    // ... somewhere in main() ...
    setGlobal() = 400; // OK

}
//setGlobal() returns a reference (to global) which is a global variable, and that is an lvalue. So it can be assigned to. The & here is not the address of operator.

