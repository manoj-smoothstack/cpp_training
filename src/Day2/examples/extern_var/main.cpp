extern void myextern(); // to avoid main.cpp:(.text+0x5): undefined reference to `myextern()'
  
int main(void) {
    myextern();
}
