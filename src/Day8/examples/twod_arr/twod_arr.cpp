#include <cassert>
#include <string.h>

int main(void) {
    // static arrays
    int dim2[2][3] = {{1, 2, 5}, {3, 2, -1}}; // array with 2 rows and 3 columns in each row
    int *dptr = &dim2[0][2];
    assert(dim2[0][1] == 2);
    assert(*++dptr == 3); // it can be treated as a 1dim array!
    
    int **dynarr = new int *[2];
    dynarr[0] = new int[3];
    int firstrow[3] = {1, 2, 5};
    memcpy(dynarr[0], firstrow, 3*sizeof(int)); // memcpy can be replaced with std::copy
    dynarr[1] = new int[3];
    int secondrow[3] = {3, 2, -1};
    memcpy(dynarr[1], secondrow, 3*sizeof(int));
    int *dynptr = &dynarr[0][2];
    assert(dynarr[0][1] == 2);
    //cout << "second row, first element = " << *++dynptr << endl;  // cannot do this for heap array
}
