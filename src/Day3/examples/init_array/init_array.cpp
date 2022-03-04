//Static initialization
int intarr[5] = { 16, 2, 77, 40, 12071 };
//int badarr[3] = { 2, 1 };  // number of elements do not match!

//Note the number of elements must match!
//Array of structs
typedef struct {
    int x;
    int y;
} ele;

//We will learn about structs later.

int main(void) {
    ele elearr[2] = {{2, 4}, {1, 7}};
}
