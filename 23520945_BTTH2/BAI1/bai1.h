#ifndef BAI1_H
#define BAI1_H

class Diem {
private:
    double iHoanh; // x-coordinate
    double iTung;  // y-coordinate

public:
    // Default constructor
    Diem();

    // Parameterized constructor
    Diem(double Hoanh, double Tung);

    // Copy constructor
    Diem(const Diem& x);

    // Methods declarations
    void Xuat();
    double GetTungDo();
    double GetHoanhDo();
    void SetTungDo(double Tung);
    void SetHoanhDo(double Hoanh);
    void TinhTien(double dx, double dy);
};

#endif
