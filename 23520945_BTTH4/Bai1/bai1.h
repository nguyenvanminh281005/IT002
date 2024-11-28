#ifndef BAI1_H
#define BAI1_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NhanVien {
protected:
    string MaSo;
    string Ten;
    double LuongCoBan;

public:
    NhanVien(const string& MaSo, const string& Ten, double LuongCoBan);
    virtual ~NhanVien() = default;
    virtual double TienThuong() const = 0;
    virtual void Xuat() const;
};

class QuanLy : public NhanVien {
private:
    double TyLeThuong;

public:
    QuanLy(const string& MaSo, const string& Ten, double LuongCoBan, double TyLeThuong);
    double TienThuong() const override;
    void Xuat() const override;
};

class KySu : public NhanVien {
private:
    int SoGioLamThem;

public:
    KySu(const string& MaSo, const string& Ten, double LuongCoBan, int SoGioLamThem);
    double TienThuong() const override;
    void Xuat() const override;
};

#endif // BAI1_H
