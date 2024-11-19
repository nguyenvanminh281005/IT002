#include <string>
using namespace std;

// Lớp cơ sở cho gia súc
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

// Lớp kế thừa cho Bò
class Bo : public GiaSuc {
public:
    Bo(int SoLuong);
    string KeuLen() const override;
    int ChoSua() const override;
    int SinhCon() const override;
};

// Lớp kế thừa cho Cừu
class Cuu : public GiaSuc {
public:
    Cuu(int SoLuong);
    string KeuLen() const override;
    int ChoSua() const override;
    int SinhCon() const override;
};

// Lớp kế thừa cho Dê
class De : public GiaSuc {
public:
    De(int SoLuong);
    string KeuLen() const override;
    int ChoSua() const override;
    int SinhCon() const override;
};
