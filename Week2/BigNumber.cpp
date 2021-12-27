#import <string>

class BigNumber {
private:
   bool overflow;
   union {
       long lnum;
       unsigned char cnum[64];
   } actualUnion;

public:
    BigNumber(long);
    BigNumber(std::string);
    BigNumber multiply(const BigNumber&) const;
    std::string number() const;
    void set(long);
    void set(std::string);
};
