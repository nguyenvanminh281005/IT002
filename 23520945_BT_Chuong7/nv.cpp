#include "nv.h"

// Định nghĩa các phương thức của lớp NhanVien
NhanVien::NhanVien(string hoTen, string ngaySinh, double luongCoBan)
    : hoTen(hoTen), ngaySinh(ngaySinh), luongCoBan(luongCoBan) {}

void NhanVien::xuatThongTin() {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
}

string NhanVien::getHoTen() {
    return hoTen;
}

// Định nghĩa các phương thức của lớp NhanVienVanPhong
NhanVienVanPhong::NhanVienVanPhong(string hoTen, string ngaySinh, double luongCoBan, int soNgayLamViec, double troCap)
    : NhanVien(hoTen, ngaySinh, luongCoBan), soNgayLamViec(soNgayLamViec), troCap(troCap) {}

double NhanVienVanPhong::tinhLuong() {
    return luongCoBan + soNgayLamViec * 200000 + troCap;
}

void NhanVienVanPhong::xuatThongTin() {
    NhanVien::xuatThongTin();
    cout << "So ngay lam viec: " << soNgayLamViec << endl;
    cout << "Tro cap: " << troCap << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

// Định nghĩa các phương thức của lớp NhanVienSanXuat
NhanVienSanXuat::NhanVienSanXuat(string hoTen, string ngaySinh, double luongCoBan, int soSanPham)
    : NhanVien(hoTen, ngaySinh, luongCoBan), soSanPham(soSanPham) {}

double NhanVienSanXuat::tinhLuong() {
    return luongCoBan + soSanPham * 2000;
}

void NhanVienSanXuat::xuatThongTin() {
    NhanVien::xuatThongTin();
    cout << "So san pham: " << soSanPham << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

// Định nghĩa các phương thức của lớp NhanVienQuanLy
NhanVienQuanLy::NhanVienQuanLy(string hoTen, string ngaySinh, double luongCoBan, double heSoChucVu, double thuong)
    : NhanVien(hoTen, ngaySinh, luongCoBan), heSoChucVu(heSoChucVu), thuong(thuong) {}

double NhanVienQuanLy::tinhLuong() {
    return luongCoBan * heSoChucVu + thuong;
}

void NhanVienQuanLy::xuatThongTin() {
    NhanVien::xuatThongTin();
    cout << "He so chuc vu: " << heSoChucVu << endl;
    cout << "Thuong: " << thuong << endl;
    cout << "Luong: " << tinhLuong() << endl;
}
