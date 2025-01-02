#ifndef FINAL_H
#define FINAL_H

#include <iostream>
#include <string>

using namespace std;

class NguoiChet {
protected:
    string ten;
    int tuoi;
    string sdt;
    string cach_chet;

public:
    NguoiChet(const string& ten, int tuoi, const string& sdt, const string& cach_chet)
            : ten(ten), tuoi(tuoi), sdt(sdt), cach_chet(cach_chet) {}

    virtual void Xuat() {
        cout << ten<<" " << tuoi << " "<< sdt<< " " << cach_chet;
    }

    string getTen() const { return ten; }
    string getCachChet() const { return cach_chet; }

    virtual ~NguoiChet() = default;
};

class chinh_tri_gia : public NguoiChet {
private:
    string chuc_vu;

public:
    chinh_tri_gia(const string& ten, int tuoi, const string& sdt, const string& cach_chet, const string& chuc_vu)
            : NguoiChet(ten, tuoi, sdt, cach_chet), chuc_vu(chuc_vu) {}

    void Xuat() override {
        NguoiChet::Xuat();
        cout <<" " << chuc_vu << endl;
    }
    string getChucVu() const { return chuc_vu; }
};

class doanh_nhan : public NguoiChet {
private:
    float tai_san;

public:
    doanh_nhan(const string& ten, int tuoi, const string& sdt, const string& cach_chet, double tai_san)
            : NguoiChet(ten, tuoi, sdt, cach_chet), tai_san(tai_san) {
        if (tai_san > 5) {
            this->cach_chet = "nang";
        } else if (tai_san > 3) {
            this->cach_chet = "binh thuong";
        } else {
            this->cach_chet = "nhe";
        }
    }

    void Xuat() override {
        NguoiChet::Xuat();
        cout <<" " << tai_san << endl;
    }
    float getTaiSan() const { return tai_san; }
};

class tu_nhan : public NguoiChet {
private:
    string toi_trang;
    int so_nam;

public:
    tu_nhan(const string& ten, int tuoi, const string& sdt, const string& cach_chet, const string& toi_trang, int so_nam)
            : NguoiChet(ten, tuoi, sdt, cach_chet), toi_trang(toi_trang), so_nam(so_nam) {
        if (so_nam > 20) {
            this->cach_chet = "nang";
        } else if (so_nam >= 10) {
            this->cach_chet = "binh thuong";
        } else {
            this->cach_chet = "nhe";
        }
    }

    void Xuat() override {
        NguoiChet::Xuat();
        cout << " " << toi_trang << " " << so_nam << endl;
    }
    int getSoNam() const { return so_nam; }
};

#endif // FINAL_H
