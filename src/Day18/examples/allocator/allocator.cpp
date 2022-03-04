#include <map>
#include <cassert>
using namespace std;

int main( ) {
   map <int, int>::allocator_type m1_Alloc;
   map <int, double>::allocator_type m3_Alloc;
   map <int, int>::allocator_type m4_Alloc;

   map <int, int> m1; // default allocator
   map <int, double, allocator<pair<int, double>> > m3; // default allocator

   m1_Alloc = m1.get_allocator( ); // getting an allocator

   // Number of pairs that can be allocated before free memory is exhausted
   // this is the theoretical limit
   //assert(m1.max_size() == 461168601842738790); // non-portable!
   //assert(m3.max_size() == 384307168202282325); // non-portable!

   map <int, int> m4( less<int>( ), m1_Alloc ); // using m1's allocator
   m4_Alloc = m4.get_allocator();
   assert(m1_Alloc == m4_Alloc); // allocator equality
}

