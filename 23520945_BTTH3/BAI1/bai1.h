#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu; // Numerator
    int mau; // Denominator
public:
    PhanSo(); // Default constructor
    PhanSo(int x, int y); // Parameterized constructor

    // Operator overloads
    PhanSo operator + (const PhanSo& b);
    PhanSo operator - (const PhanSo& b);
    PhanSo operator * (const PhanSo& b);
    PhanSo operator / (const PhanSo& b);

    bool operator == (const PhanSo& b);
    bool operator != (const PhanSo& b);
    bool operator >= (const PhanSo& b);
    bool operator <= (const PhanSo& b);
    bool operator < (const PhanSo& b);
    bool operator > (const PhanSo& b);

    // Friend functions
    friend istream& operator>>(istream &in, PhanSo &b);
    friend ostream& operator<<(ostream& os, const PhanSo& b);
};

#endif // SOPHUC_H
