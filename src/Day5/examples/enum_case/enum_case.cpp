//Example of how you can use an enum.
enum Constants {
     EXAMPLE_CONSTANT = 10,
     ANOTHER_CONSTANT = 20
};
int main(void) {
    switch(Constants::EXAMPLE_CONSTANT) {
        case Constants::EXAMPLE_CONSTANT:
             // block code
        case Constants::ANOTHER_CONSTANT:
            break;
    };
}
