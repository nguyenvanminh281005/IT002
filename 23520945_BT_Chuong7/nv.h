#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Lớp cha NhanVien
class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luongCoBan;

public:
    NhanVien(string hoTen, string ngaySinh, double luongCoBan);
    virtual double tinhLuong() = 0;
    virtual void xuatThongTin();
    string getHoTen();
};

// Lớp con NhanVienVanPhong
class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
    double troCap;

public:
    NhanVienVanPhong(string hoTen, string ngaySinh, double luongCoBan, int soNgayLamViec, double troCap);
    double tinhLuong() override;
    void xuatThongTin() override;
};

// Lớp con NhanVienSanXuat
class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NhanVienSanXuat(string hoTen, string ngaySinh, double luongCoBan, int soSanPham);
    double tinhLuong() override;
    void xuatThongTin() override;
};

// Lớp con NhanVienQuanLy
class NhanVienQuanLy : public NhanVien {
private:
    double heSoChucVu;
    double thuong;

public:
    NhanVienQuanLy(string hoTen, string ngaySinh, double luongCoBan, double heSoChucVu, double thuong);
    double tinhLuong() override;
    void xuatThongTin() override;
};

#endif
