#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
public:
    PhanSo();
    PhanSo(int x, int y);

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

    friend istream& operator>>(istream &in, PhanSo &b);
    friend ostream& operator<<(ostream& os, const PhanSo& b);
};

#endif // SOPHUC_H
