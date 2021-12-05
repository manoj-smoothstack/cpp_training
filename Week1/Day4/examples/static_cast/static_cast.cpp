int main(void) {
    //static_cast operators resolve at compile time and do not remove any const or volatile modifiers.
    //A C-style cast does not give us compile time checking.
    float f = 3.5;
    int a = f;  // C style cast
    int b = static_cast<int>(f);
    
    //Now if you do the following:
    
    char c = 'a';
    int* q = (int*)&c;
    //int* p = static_cast<int*>(&c);
    
    //You will get an error on invalid static_cast from type char* to int*.
}
