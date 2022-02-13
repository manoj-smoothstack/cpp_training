#include <cassert>

int main() {
   using namespace std;
   int n = [] (int x, int y) { return x + y; }(5, 4);
   assert(n == 9);
}

