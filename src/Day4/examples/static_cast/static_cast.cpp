int main(void) {
    //static_cast operators resolve at compile time.
    //A C-style cast does not give us compile time checking.
    float f = 3.5;
    int a = f;  // C style cast
    int b = static_cast<int>(f);
    
    char c = 'a';
    int* q = (int*)&c;
    //int* p = static_cast<int*>(&c);
    //You will get an error on invalid static_cast from type char* to int*.
    char d = 'b';
    int ii = static_cast<int>(d);  // safe conversion
    char e = static_cast<char>(ii); // unsafe conversion but static_cast allows it
    float ff = static_cast<float>(ii);
}

