#include "bai1.h"

// Định nghĩa phương thức của lớp NhanVien
NhanVien::NhanVien(const string &MaSo, const string &Ten, double LuongCoBan): MaSo(MaSo), Ten(Ten), LuongCoBan(LuongCoBan) {}

void NhanVien::Xuat() const {
    cout << "Ma So: " << MaSo << endl;
    cout << "Ten: " << Ten << endl;
    cout << "Luong Co Ban: " << fixed << setprecision(0) << LuongCoBan << endl;
}

// Định nghĩa phương thức của lớp QuanLy
QuanLy::QuanLy(const string &MaSo, const string &Ten, double LuongCoBan, double TyLeThuong): NhanVien(MaSo, Ten, LuongCoBan), TyLeThuong(TyLeThuong) {}

double QuanLy::TienThuong() const {
    return LuongCoBan * TyLeThuong;
}

void QuanLy::Xuat() const {
    NhanVien::Xuat();
    cout << "Ty Le Thuong: " << TyLeThuong << endl;
    cout << "Tien Thuong: " << fixed << setprecision(0) << TienThuong() << endl;
}

// Định nghĩa phương thức của lớp KySu
KySu::KySu(const string &MaSo, const string &Ten, double LuongCoBan, int SoGioLamThem): NhanVien(MaSo, Ten, LuongCoBan), SoGioLamThem(SoGioLamThem) {}

double KySu::TienThuong() const {
    return SoGioLamThem * 100000;
}

void KySu::Xuat() const {
    NhanVien::Xuat();
    cout << "So Gio Lam Them: " << SoGioLamThem << endl;
    cout << "Tien Thuong: " << fixed << setprecision(0) << TienThuong() << endl;
}