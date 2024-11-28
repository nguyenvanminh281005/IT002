#include "sophuc.h"
using namespace std;
SoPhuc::SoPhuc() : dthuc(0), dao(0) {}

SoPhuc::SoPhuc(double x, double y) : dthuc(x), dao(y) {}

SoPhuc SoPhuc::operator + (const SoPhuc& b) {
    return SoPhuc(dthuc + b.dthuc, dao + b.dao);
}

SoPhuc SoPhuc::operator - (const SoPhuc& b) {
    return SoPhuc(dthuc - b.dthuc, dao - b.dao);
}

SoPhuc SoPhuc::operator * (const SoPhuc& b) {
    return SoPhuc(dthuc * b.dthuc - dao * b.dao, dthuc * b.dao + dao * b.dthuc);
}

SoPhuc SoPhuc::operator / (const SoPhuc& b) {
    double mau = b.dthuc * b.dthuc + b.dao * b.dao;
    if (mau == 0) {
        throw invalid_argument("Mẫu số không thể bằng 0");
    }
    return SoPhuc((dthuc * b.dthuc + dao * b.dao) / mau, (dao * b.dthuc - dthuc * b.dao) / mau);
}

bool SoPhuc::operator == (const SoPhuc& b) {
    return (dthuc == b.dthuc) && (dao == b.dao);
}

bool SoPhuc::operator != (const SoPhuc& b) {
    return !(*this == b);
}
// ham nhap
istream& operator>>(istream& in, SoPhuc& b) {
    cout << "Nhap phan thuc: ";
    in >> b.dthuc;
    cout << "Nhap phan ao: ";
    in >> b.dao;
    return in;
}
//ham xuat
ostream& operator<<(ostream& os, const SoPhuc& b) {
    os << b.dthuc << (b.dao >= 0 ? "+" : "") << b.dao << "i";
    return os;
}
