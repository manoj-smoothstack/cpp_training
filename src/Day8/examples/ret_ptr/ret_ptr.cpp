int* getdata() {
    // some code
    return new int[10]; // is this expected
}

int main(void) {
    int* ptr = getdata();
    // some code
    delete [] ptr;  // need to know that you have to delete it
}
