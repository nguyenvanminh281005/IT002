#include "sophuc.h"

// Hàm khởi tạo mặc định
SoPhuc::SoPhuc() : dthuc(0), dao(0) {}

// Hàm khởi tạo với tham số
SoPhuc::SoPhuc(double x, double y) : dthuc(x), dao(y) {}

// Toán tử cộng
SoPhuc SoPhuc::operator + (const SoPhuc& b) {
    return SoPhuc(dthuc + b.dthuc, dao + b.dao);
}

// Toán tử trừ
SoPhuc SoPhuc::operator - (const SoPhuc& b) {
    return SoPhuc(dthuc - b.dthuc, dao - b.dao);
}

// Toán tử nhân
SoPhuc SoPhuc::operator * (const SoPhuc& b) {
    return SoPhuc(dthuc * b.dthuc - dao * b.dao, dthuc * b.dao + dao * b.dthuc);
}

// Toán tử chia
SoPhuc SoPhuc::operator / (const SoPhuc& b) {
    double mau = b.dthuc * b.dthuc + b.dao * b.dao;
    if (mau == 0) {
        throw invalid_argument("Mẫu số không thể bằng 0");
    }
    return SoPhuc((dthuc * b.dthuc + dao * b.dao) / mau, (dao * b.dthuc - dthuc * b.dao) / mau);
}

// Toán tử so sánh bằng
bool SoPhuc::operator == (const SoPhuc& b) {
    return (dthuc == b.dthuc) && (dao == b.dao);
}

// Toán tử so sánh khác
bool SoPhuc::operator != (const SoPhuc& b) {
    return !(*this == b);
}

// Hàm bạn bè nhập số phức
istream& operator>>(istream& in, SoPhuc& b) {
    cout << "Nhap phan thuc: ";
    in >> b.dthuc;
    cout << "Nhap phan ao: ";
    in >> b.dao;
    return in;
}

// Hàm bạn bè xuất số phức
ostream& operator<<(ostream& os, const SoPhuc& b) {
    os << b.dthuc << (b.dao >= 0 ? "+" : "") << b.dao << "i";
    return os;
}
