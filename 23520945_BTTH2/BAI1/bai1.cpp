#include "bai1.h"
#include <iostream>

using namespace std;

// Default constructor
Diem::Diem() : iHoanh(0), iTung(0) {}

// Parameterized constructor
Diem::Diem(double Hoanh, double Tung) : iHoanh(Hoanh), iTung(Tung) {}

// Copy constructor
Diem::Diem(const Diem& x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

// Method to display the point coordinates
void Diem::Xuat() {
    cout << "(" << iHoanh << ", " << iTung << ")" << endl;
}

// Getter for TungDo (y-coordinate)
double Diem::GetTungDo() {
    return iTung;
}

// Getter for HoanhDo (x-coordinate)
double Diem::GetHoanhDo() {
    return iHoanh;
}

// Setter for TungDo (y-coordinate)
void Diem::SetTungDo(double Tung) {
    iTung = Tung;
}

// Setter for HoanhDo (x-coordinate)
void Diem::SetHoanhDo(double Hoanh) {
    iHoanh = Hoanh;
}

// Translate the point by dx (x direction) and dy (y direction)
void Diem::TinhTien(double dx, double dy) {
    iHoanh += dx;
    iTung += dy;
}
