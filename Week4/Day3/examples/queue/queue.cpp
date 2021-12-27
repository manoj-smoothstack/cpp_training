#include <queue>
#include <vector>
#include <list>
#include <cassert>

using namespace std;

int main( ) {
   // Declares queue with default deque base container
   queue <char> q1;
   // Explicitly declares a queue with deque base container
   queue <char, deque<char> > q2;
   // These lines don't cause an error, even though they
   // declares a queue with a vector base container
   queue <int, vector<int> > q3;
   q3.push( 10 );
   // but the following would cause an error because vector has
   // no pop_front member function
   // q3.pop( );
   // Declares a queue with list base container
   queue <int, list<int> > q4;
   // The second member function copies elements from a container
   list<int> li1;
   li1.push_back( 1 );
   li1.push_back( 2 );
   queue <int, list<int> > q5( li1 );
   assert(q5.front() == 1);
   assert(q5.back() == 2);
}

