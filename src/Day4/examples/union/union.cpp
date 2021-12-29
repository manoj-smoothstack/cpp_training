#include <cassert>
#include <cstring>

union U {
    long lnum; 
    char cnum[6];
};

int main(void) {
    U u;
    memset(u.cnum, 0, 6);
    u.lnum = 10L;
    assert(u.cnum[5] == 4);
    //assert(u.lnum == 10);
}
