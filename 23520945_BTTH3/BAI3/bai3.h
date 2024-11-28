#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>
using namespace std;

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:

    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);

    int TinhGiay() const;
    void TinhLaiGio(int Giay);

    ThoiGian operator+(int Giay);
    ThoiGian operator-(int Giay);
    ThoiGian operator+(const ThoiGian& a);
    ThoiGian operator-(const ThoiGian& a);

    ThoiGian& operator++();
    ThoiGian operator++(int);
    ThoiGian& operator--();
    ThoiGian operator--(int);

    bool operator==(const ThoiGian& a);
    bool operator!=(const ThoiGian& a);
    bool operator>=(const ThoiGian& a);
    bool operator<=(const ThoiGian& a);
    bool operator>(const ThoiGian& a);
    bool operator<(const ThoiGian& a);
    
    friend ostream& operator<<(ostream& os, const ThoiGian& tg);
    friend istream& operator>>(istream& is, ThoiGian& tg);
};

#endif // THOIGIAN_H
