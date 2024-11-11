#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>
using namespace std;

class ThoiGian {
private:
    int iGio;   // Số giờ
    int iPhut;  // Số phút
    int iGiay;  // Số giây

public:
    // Constructors
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);

    // Phương thức hỗ trợ
    int TinhGiay() const;
    void TinhLaiGio(int Giay);

    // Toán tử
    ThoiGian operator+(int Giay);
    ThoiGian operator-(int Giay);
    ThoiGian operator+(const ThoiGian& a);
    ThoiGian operator-(const ThoiGian& a);

    // Toán tử tăng, giảm
    ThoiGian& operator++();    // Tiền tố
    ThoiGian operator++(int);  // Hậu tố
    ThoiGian& operator--();    // Tiền tố
    ThoiGian operator--(int);  // Hậu tố

    // Toán tử so sánh
    bool operator==(const ThoiGian& a);
    bool operator!=(const ThoiGian& a);
    bool operator>=(const ThoiGian& a);
    bool operator<=(const ThoiGian& a);
    bool operator>(const ThoiGian& a);
    bool operator<(const ThoiGian& a);

    // Toán tử nhập, xuất
    friend ostream& operator<<(ostream& os, const ThoiGian& tg);
    friend istream& operator>>(istream& is, ThoiGian& tg);
};

#endif // THOIGIAN_H
