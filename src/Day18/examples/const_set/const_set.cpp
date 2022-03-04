#include <set>
#include <iostream>

int main( ) {
   using namespace std;
   const set<int> s1 = {1, 2, 3};
   //s1 = {4}; // error: no viable overloaded '='
}
