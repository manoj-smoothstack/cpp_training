#include <iostream>
#include <vector>
#include <list>
#include <cassert>
 
template<class T>
typename std::iterator_traits<T>::value_type get_value(T first) {
    //typename std::iterator_traits<T>::value_type tmp = *first;
    return typename std::iterator_traits<T>::value_type{};
    //return tmp;
}
 
int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    int i = get_value(v.begin());
    std::cout << i << std::endl;
}

