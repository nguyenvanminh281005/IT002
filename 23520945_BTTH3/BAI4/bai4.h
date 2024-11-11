#ifndef BAI4_H
#define BAI4_H

#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;
    bool KiemTraNamNhuan(int nam) const;
    int SoNgayTrongThang(int thang, int nam) const;
    void DieuChinhNgay();

public:
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);
    int TinhNgay() const;

    NgayThangNam operator+(int ngay);
    NgayThangNam operator-(int ngay);
    int operator-(const NgayThangNam& a);

    NgayThangNam& operator++();
    NgayThangNam& operator--();

    bool operator==(const NgayThangNam& a) const;
    bool operator!=(const NgayThangNam& a) const;
    bool operator>=(const NgayThangNam& a) const;
    bool operator<=(const NgayThangNam& a) const;
    bool operator>(const NgayThangNam& a) const;
    bool operator<(const NgayThangNam& a) const;

    friend istream& operator>>(istream& in, NgayThangNam& nt);
    friend ostream& operator<<(ostream& out, const NgayThangNam& nt);
};

#endif
