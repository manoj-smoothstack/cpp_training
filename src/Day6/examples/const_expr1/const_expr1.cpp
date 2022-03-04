constexpr int array_size2(int x) { 
    return x+1; 
} 

int main(void) {
    // OK, constexpr functions can be evaluated at compile time
    // and used in contexts that require constant expressions. 
    int array[array_size2(10)];  
}

