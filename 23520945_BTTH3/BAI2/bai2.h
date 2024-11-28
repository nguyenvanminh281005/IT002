#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double dthuc;
    double dao;
public:

    SoPhuc();
    SoPhuc(double x, double y);

    SoPhuc operator + (const SoPhuc& b);
    SoPhuc operator - (const SoPhuc& b);
    SoPhuc operator * (const SoPhuc& b);
    SoPhuc operator / (const SoPhuc& b);

    bool operator == (const SoPhuc& b);
    bool operator != (const SoPhuc& b);

    friend istream& operator>>(istream& in, SoPhuc& b);
    friend ostream& operator<<(ostream& os, const SoPhuc& b);
};

#endif // SOPHUC_H
