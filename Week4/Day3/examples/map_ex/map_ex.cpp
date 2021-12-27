#include <map>
#include <cassert>

typedef std::map<char, int> Mymap;
int main() {
    Mymap c1;

    c1.insert(Mymap::value_type('a', 1));
    c1.insert(Mymap::value_type('b', 2));
    c1.insert(Mymap::value_type('c', 3));

    assert(c1.at('a') == 1);
    assert(c1.at('b') == 2);
    assert(c1.at('c') == 3);
}

