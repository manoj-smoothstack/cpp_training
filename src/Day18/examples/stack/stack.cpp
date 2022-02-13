#include <stack>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

int main( ) {
   // Declares stack with default deque base container
   stack <char> dsc1;
   //Explicitly declares a stack with deque base container
   stack <char, deque<char> > dsc2;
   // Declares a stack with vector base containers
   stack <int, vector<int> > vsi1;
   // Declares a stack with list base container
   stack <int, list<int> > lsi;
   // The second member function copies elements from a container
   vector<int> v1;
   v1.push_back(1);
   stack <int, vector<int> > vsi2( v1 );
   assert(vsi2.top() == 1);
}

