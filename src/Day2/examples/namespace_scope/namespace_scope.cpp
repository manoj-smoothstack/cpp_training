namespace N { // scope of N begins (as a member of global namespace)
    int i; // scope of i begins
    int g(int a) { return a; } // scope of g begins
    int j(); // scope of j begins
    void q(); // scope of q begins
    namespace {
        int x; // scope of x begins
    } // scope of x continues (member of unnamed namespace)
    inline namespace inl { // scope of inl begins
        int y; // scope of y begins
    } // scope of y continues (member of inline namespace)
} // scopes of i, g, j, q, inl, x, and y pause
 
namespace {
    int l = 1; // scope of l begins
} // scope of l continues (member of unnamed namespace)
 
namespace N { // scopes of i, g, j, q, inl, x, and y resume
    int g(char a) { // overloads N::g(int)
        return l + a; // l from unnamed namespace is in scope
    }
//  int i; // error: duplicate definition (i is already in scope)
    int j(); // OK: duplicate function declaration is allowed
    int j() { // OK: definition of the earlier-declared N::j()
        return g(i); // calls N::g(int)
    }
//  int q(); // error: q is already in scope with a different return type
} // scopes of i, g, j, q, inl, x, and y pause
 
int main() {
    using namespace N; // scopes of i, g, j, q, inl, x, and y resume
    i = 1; // N::i is in scope
    x = 1; // N::(anonymous)::x is in scope
    y = 1; // N::inl::y is in scope
    inl::y = 2; // N::inl is also in scope
} // scopes of i, g, j, q, inl, x, and y end

