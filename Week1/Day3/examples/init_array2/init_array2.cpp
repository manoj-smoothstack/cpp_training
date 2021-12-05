#include <cassert>

int main(void) {
    //Default initialization
    int ii[3];
    //assert(ii[2] == 0);  // is this true?
    
    //So you need to use the aggregate initializer here to guarantee that this is initialized correctly. 
    int jj[3] = {};  // OR
    int kk[3] = {0};
}
