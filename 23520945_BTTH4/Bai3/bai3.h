#ifndef BAI3_H
#define BAI3_H

#include <string>
using namespace std;

class GiaSuc {
protected:
    int SoLuong;

public:
    GiaSuc(int SoLuong);
    virtual ~GiaSuc() {}

    virtual string KeuLen() const = 0;
    virtual int ChoSua() const = 0;
    virtual int SinhCon() const = 0;

    int LaySoLuong() const;
    void ThemSoLuong(int SoConMoi);
};

class Bo : public GiaSuc {
public:
    Bo(int SoLuong);
    string KeuLen() const override;
    int ChoSua() const override;
    int SinhCon() const override;
};

class Cuu : public GiaSuc {
public:
    Cuu(int SoLuong);
    string KeuLen() const override;
    int ChoSua() const override;
    int SinhCon() const override;
};

class De : public GiaSuc {
public:
    De(int SoLuong);
    string KeuLen() const override;
    int ChoSua() const override;
    int SinhCon() const override;
};

#endif // BAI3_H
