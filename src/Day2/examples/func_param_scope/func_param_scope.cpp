#include <exception>

const int n = 3;
 
int f1(
    int n // scope of function parameter n begins,
          // scope of global n pauses
//  , int y = n // error: default argument references a function parameter
);
 
int (*(*f2)(int n))[n]; // OK: scope of function parameter n
                        // ends at the end of its function declarator
                        // in the array declarator, global n is in scope
// declares a pointer to function returning a pointer to an array of 3 int
 
//auto (*f3)(int n)->int (*)[n]; // error: function parameter n as array bound
 
void f(int n = 2) // scope of function parameter n begins
try // function try block
{ // function body begins
    ++n; // function parameter n is in scope
    {
        int n = 2; // scope of local n begins
                   // scope of function parameter n pauses
        ++n; // local n is in scope
    } // scope of local n ends
      // scope of function parameter n resumes
} catch (std::exception& e) {
    ++n; // function parameter n is in scope
    throw;
} // last exception handler ends, scope of function parameter n ends
 
int a = n; // global n is in scope

int main(void) {

}
