// Trailing return type is used to represent 
// a fully generic return type for a+b.
template <typename FirstType, typename SecondType> 
auto add(FirstType a, SecondType b) -> decltype(a + b) {
   return a + b;
}

int main() {
   // The first template argument is of the integer type, and
   // the second template argument is of the character type.
   add(1, 'A'); 

   // Both the template arguments are of the integer type.
   add(3, 5); 
}

