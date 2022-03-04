#include <cassert>

int main(void) {
    for (int x = 0; x < 10; x++) {
        for (int y=0; y < 10; y++) {
            static int number_of_times = 0;
            number_of_times++;
        }
    }
}

