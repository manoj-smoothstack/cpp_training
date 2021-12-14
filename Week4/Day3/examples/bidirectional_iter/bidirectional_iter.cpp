#include <iostream>
#include <vector>
#include <list>
#include <cassert>
 
template<class T>
void my_reverse(T first, T last) {
    typename std::iterator_traits<T>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) { // go double speed or half the number of iterations
        typename std::iterator_traits<T>::value_type tmp = *first;
        std::cout << tmp << std::endl;
        *first++ = *--last;
        *last = tmp;
    }
}
 
int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::vector<int> rv{5, 4, 3, 2, 1};
    my_reverse(v.begin(), v.end());
    assert(v == rv);
 
    std::list<int> l{1, 2, 3, 4, 5};
    std::list<int> rl{5, 4, 3, 2, 1};
    my_reverse(l.begin(), l.end());
    assert(l == rl);
 
    int a[] = {1, 2, 3, 4, 5};
    int ra[] = {5, 4, 3, 2, 1};
    my_reverse(a, a + std::size(a));
    for (int i = 0; i < std::size(a); i++)
        assert(a[i] == ra[i]);
}

