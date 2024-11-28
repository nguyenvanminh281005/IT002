#include "bai3.h"
#include <iostream>
#include <cstdlib>

using namespace std;

GiaSuc::GiaSuc(int SoLuong) : SoLuong(SoLuong) {}

int GiaSuc::LaySoLuong() const {
    return SoLuong;
}

void GiaSuc::ThemSoLuong(int SoConMoi) {
    SoLuong += SoConMoi;
}

Bo::Bo(int SoLuong) : GiaSuc(SoLuong) {}

string Bo::KeuLen() const {
    return "UmBo!";
}

int Bo::ChoSua() const {
    return rand() % 21;
}

int Bo::SinhCon() const {
    return rand() % 4;
}

Cuu::Cuu(int SoLuong) : GiaSuc(SoLuong) {}

string Cuu::KeuLen() const {
    return "Be!";
}

int Cuu::ChoSua() const {
    return rand() % 6;
}

int Cuu::SinhCon() const {
    return rand() % 3;
}

De::De(int SoLuong) : GiaSuc(SoLuong) {}

string De::KeuLen() const {
    return "Beeeee!";
}

int De::ChoSua() const {
    return rand() % 11;
}

int De::SinhCon() const {
    return rand() % 3;
}