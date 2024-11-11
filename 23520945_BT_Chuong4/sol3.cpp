#include <bits/stdc++.h>
using namespace std;

class DonThuc {
public:
    double a;
    int b;

    DonThuc(double a = 0, int b = 0) : a(a), b(b) {}

    void nhap() {
        cout << "Nhap he so: ";
        cin >> a;
        cout << "Nhap so mu: ";
        cin >> b;
    }

    void xuat() const {
        if (a == 0) {
            cout << 0;
        } else if (b == 0) {
            cout << a;
        } else if (b == 1) {
            cout << a << "x";
        } else {
            cout << a << "x^" << b;
        }
    }

    double tinhGiaTri(double x) const {
        return a * pow(x, b);
    }

    DonThuc daoHam() const {
        if (b == 0) {
            return DonThuc(0, 0);
        }
        return DonThuc(a * b, b - 1);
    }

    DonThuc tong(const DonThuc& other) const {
        if (b == other.b) {
            return DonThuc(a + other.a, b);
        } else {
            return DonThuc(0, -1);
        }
    }
};

int main() {
    DonThuc dt1, dt2;

    cout << "Nhap don thuc thu 1: \n";
    dt1.nhap();
    cout << "Nhap don thuc thu 2: \n";
    dt2.nhap();

    cout << "Don thuc 1: ";
    dt1.xuat();
    cout << endl;

    cout << "Don thuc 2: ";
    dt2.xuat();
    cout << endl;

    if (dt1.b == dt2.b) {
        DonThuc sum = dt1.tong(dt2);
        cout << "Tong 2 don thuc: ";
        sum.xuat();
        cout << endl;
    } else {
        cout << "Hai don thuc khong cung bac, khong tinh tong duoc." << endl;
    }

    return 0;
}
