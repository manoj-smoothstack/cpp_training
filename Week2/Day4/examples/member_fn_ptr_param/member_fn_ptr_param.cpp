#include <cassert>
  
class Comparator {
    public:
        bool lessthan(int x, int y) {
            return x < y;
        }
};

class Sorter {
    public:
        typedef bool (Comparator::*memfn)(int x, int y);
        memfn lessfn;
        Comparator* c;
        void register_comparator(Comparator* c, memfn ptr) {
            lessfn = ptr;
            this->c = c;
        };
        bool compare(int x, int y) {
            return (c->*lessfn)(x, y);
        };
};

int main(void) {
    Comparator c;
    Sorter sorter;
    sorter.register_comparator(&c, &Comparator::lessthan);
    assert(sorter.compare(2, 4));
}
