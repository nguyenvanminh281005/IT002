#include "bai3.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Triển khai lớp cơ sở GiaSuc
GiaSuc::GiaSuc(int SoLuong) : SoLuong(SoLuong) {}

int GiaSuc::LaySoLuong() const {
    return SoLuong;
}

void GiaSuc::ThemSoLuong(int SoConMoi) {
    SoLuong += SoConMoi;
}

// Triển khai lớp Bo
Bo::Bo(int SoLuong) : GiaSuc(SoLuong) {}

string Bo::KeuLen() const {
    return "UmBo!";
}

int Bo::ChoSua() const {
    return rand() % 21; // 0 - 20 lít
}

int Bo::SinhCon() const {
    return rand() % 4; // 0 - 3 con
}

// Triển khai lớp Cuu
Cuu::Cuu(int SoLuong) : GiaSuc(SoLuong) {}

string Cuu::KeuLen() const {
    return "Be!";
}

int Cuu::ChoSua() const {
    return rand() % 6; // 0 - 5 lít
}

int Cuu::SinhCon() const {
    return rand() % 3; // 0 - 2 con
}

// Triển khai lớp De
De::De(int SoLuong) : GiaSuc(SoLuong) {}

string De::KeuLen() const {
    return "Beeeee!";
}

int De::ChoSua() const {
    return rand() % 11; // 0 - 10 lít
}

int De::SinhCon() const {
    return rand() % 3; // 0 - 2 con
}