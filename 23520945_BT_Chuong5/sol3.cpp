#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int n;
    vector<double> heSo;

public:
    DaThuc(int bac) {
        n = bac;
        heSo.resize(n + 1, 0);
    }

    int layBac() const {
        return n;
    }

    double layheSo(int i) const {
        return heSo[i];
    }

    double tinhGiaTri(double x) const {
        double result = 0;
        double power = 1;
        for (int i = n; i >= 0; --i) {
            result += heSo[i] * power;
            power *= x;
        }
        return result;
    }

    friend istream &operator>>(istream &is, DaThuc &dt) {
        for (int i = 0; i <= dt.n; ++i) {
            cout << "He so cua x^" << dt.n - i << ": ";
            is >> dt.heSo[i];
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, const DaThuc &dt) {
        bool first = true;
        for (int i = dt.n; i >= 0; --i) {
            if (dt.heSo[i] != 0) {
                if (!first && dt.heSo[i] > 0) {
                    os << " + ";
                } else if (dt.heSo[i] < 0) {
                    os << " - ";
                }

                os << abs(dt.heSo[i]);
                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }
                first = false;
            }
        }
        if (first) {
            os << "0";
        }
        return os;
    }

    DaThuc operator+(const DaThuc &other) const {
        int maxBac = max(n, other.n);
        DaThuc result(maxBac);

        for (int i = 0; i <= maxBac; ++i) {
            if (i <= n) result.heSo[maxBac - i] += heSo[n - i];
            if (i <= other.n) result.heSo[maxBac - i] += other.heSo[other.n - i];
        }
        return result;
    }

    DaThuc operator-(const DaThuc &other) const {
        int maxBac = max(n, other.n);
        DaThuc result(maxBac);

        for (int i = 0; i <= maxBac; ++i) {
            if (i <= n) result.heSo[maxBac - i] += heSo[n - i];
            if (i <= other.n) result.heSo[maxBac - i] -= other.heSo[other.n - i];
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Nhap bac cua da thuc thu nhat:\n";
    cin >> n;
    DaThuc dt1(n);
    cin >> dt1;

    cout << "Nhap bac cua da thuc thu hai:\n";
    cin >> n;
    DaThuc dt2(n);
    cin >> dt2;

    cout << "Da thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    DaThuc dtSum = dt1 + dt2;
    cout << "Tong cua hai da thuc: " << dtSum << endl;

    DaThuc dtMinus = dt1 - dt2;
    cout << "Hieu cua hai da thuc: " << dtMinus << endl;

    double x;
    cout << "Nhap gia tri cua x de tinh gia tri da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << dt1.tinhGiaTri(x) << endl;

    return 0;
}
