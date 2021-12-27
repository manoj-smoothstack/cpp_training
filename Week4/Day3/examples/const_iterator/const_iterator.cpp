#include <vector>
#include <cassert>
using namespace std;

int main(void) {
    vector<int> vec{1, 2, 3};
    vector<int>::iterator it = vec.begin();
    assert(vec[0] == 1);
    *it = 4;
    assert(vec[0] == 4);
    vector<int>::const_iterator cit = vec.cbegin();
    //*cit = 7; //error: cannot assign to return value because function 'operator*' returns a const value
}

