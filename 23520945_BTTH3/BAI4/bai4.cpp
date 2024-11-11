#include "bai4.h"

NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNam(Nam), iThang(Thang), iNgay(Ngay) {
    DieuChinhNgay();
}

bool NgayThangNam::KiemTraNamNhuan(int nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int NgayThangNam::SoNgayTrongThang(int thang, int nam) const {
    if (thang == 2)
        return KiemTraNamNhuan(nam) ? 29 : 28;
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        return 30;
    else
        return 31;
}

void NgayThangNam::DieuChinhNgay() {
    while (iNgay > SoNgayTrongThang(iThang, iNam)) {
        iNgay -= SoNgayTrongThang(iThang, iNam);
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    while (iNgay <= 0) {
        iThang--;
        if (iThang <= 0) {
            iThang = 12;
            iNam--;
        }
        iNgay += SoNgayTrongThang(iThang, iNam);
    }
}

int NgayThangNam::TinhNgay() const {
    return iNam * 365 + iThang * 30 + iNgay;
}

NgayThangNam NgayThangNam::operator+(int ngay) {
    NgayThangNam result = *this;
    result.iNgay += ngay;
    result.DieuChinhNgay();
    return result;
}

NgayThangNam NgayThangNam::operator-(int ngay) {
    NgayThangNam result = *this;
    result.iNgay -= ngay;
    result.DieuChinhNgay();
    return result;
}

int NgayThangNam::operator-(const NgayThangNam& a) {
    return this->TinhNgay() - a.TinhNgay();
}

NgayThangNam& NgayThangNam::operator++() {
    iNgay++;
    DieuChinhNgay();
    return *this;
}

NgayThangNam& NgayThangNam::operator--() {
    iNgay--;
    DieuChinhNgay();
    return *this;
}

bool NgayThangNam::operator==(const NgayThangNam& a) const {
    return iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam;
}

bool NgayThangNam::operator!=(const NgayThangNam& a) const {
    return !(*this == a);
}

bool NgayThangNam::operator>=(const NgayThangNam& a) const {
    return TinhNgay() >= a.TinhNgay();
}

bool NgayThangNam::operator<=(const NgayThangNam& a) const {
    return TinhNgay() <= a.TinhNgay();
}

bool NgayThangNam::operator>(const NgayThangNam& a) const {
    return TinhNgay() > a.TinhNgay();
}

bool NgayThangNam::operator<(const NgayThangNam& a) const {
    return TinhNgay() < a.TinhNgay();
}

istream& operator>>(istream& in, NgayThangNam& nt) {
    cout << "Nhap ngay: ";
    in >> nt.iNgay;
    cout << "Nhap thang: ";
    in >> nt.iThang;
    cout << "Nhap nam: ";
    in >> nt.iNam;
    nt.DieuChinhNgay();
    return in;
}

ostream& operator<<(ostream& out, const NgayThangNam& nt) {
    out << nt.iNgay << "/" << nt.iThang << "/" << nt.iNam;
    return out;
}
