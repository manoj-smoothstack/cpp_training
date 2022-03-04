class Desk {};

class SlowStudent {
    private:
        Desk d;
        const int ii;  // cannot do this without initialization list below
        Desk getDesk() {
            return Desk();
        }
    public:
        SlowStudent() : ii(4) {
            d = getDesk();
            //ii = 4; // cannot do this
        }
};

int main(void) {
    SlowStudent s;
}
