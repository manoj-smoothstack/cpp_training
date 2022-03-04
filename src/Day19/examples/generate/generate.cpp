#include <deque>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <cassert>

using namespace std;

int main() {
    deque<int> deq1(5);
    deque<int>::iterator d1_Iter;

    // Assigning random values to deque integer elements
    generate (deq1.begin(), deq1.end(), rand);

    int r[] = {1804289383, 846930886, 1681692777, 1714636915, 1957747793};

    int ii = 0;
    for (auto ele : deq1) {
        assert(r[ii] == ele);
        ii++;
    }
}

