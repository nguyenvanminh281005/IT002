#include "bai3.h"
using namespace std;

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    if (iGiay >= 60) {
        iPhut += iGiay / 60;
        iGiay %= 60;
    }
    if (iPhut >= 60) {
        iGio += iPhut / 60;
        iPhut %= 60;
    }
}

int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    iPhut = (Giay % 3600) / 60;
    iGiay = Giay % 60;
}

ThoiGian ThoiGian::operator+(int Giay) {
    ThoiGian result = *this;
    result.TinhLaiGio(result.TinhGiay() + Giay);
    return result;
}

ThoiGian ThoiGian::operator-(int Giay) {
    ThoiGian result = *this;
    result.TinhLaiGio(result.TinhGiay() - Giay);
    return result;
}

ThoiGian ThoiGian::operator+(const ThoiGian& a) {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + a.TinhGiay());
    return result;
}

ThoiGian ThoiGian::operator-(const ThoiGian& a) {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - a.TinhGiay());
    return result;
}

ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

bool ThoiGian::operator==(const ThoiGian& a) {
    return TinhGiay() == a.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& a) {
    return !(*this == a);
}

bool ThoiGian::operator>=(const ThoiGian& a) {
    return TinhGiay() >= a.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& a) {
    return TinhGiay() <= a.TinhGiay();
}

bool ThoiGian::operator>(const ThoiGian& a) {
    return TinhGiay() > a.TinhGiay();
}

bool ThoiGian::operator<(const ThoiGian& a) {
    return TinhGiay() < a.TinhGiay();
}

// cout
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << "h " <<
