#include <bits/stdc++.h>
using namespace std;

class DaThuc {
private:
    int bac;
    vector<double> heSo;

public:
    DaThuc(int bac = 0) : bac(bac) {
        heSo.resize(bac + 1, 0);
    }

    void nhap() {
        for (int i = bac; i >= 0; --i) {
            cout << "Nhap he so cua x^" << i << ": ";
            cin >> heSo[i];
        }
    }

    void xuat() const {
        bool first = true;
        for (int i = bac; i >= 0; --i) {
            if (heSo[i] != 0) {
                if (!first) {
                    cout << (heSo[i] > 0 ? " + " : " - ");
                } else if (heSo[i] < 0) {
                    cout << "-";
                }
                cout << abs(heSo[i]);
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
                first = false;
            }
        }
        if (first) {
            cout << "0";
        }
        cout << endl;
    }

    double tinhGiaTri(double x) const {
        double ketQua = 0;
        for (int i = 0; i <= bac; ++i) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }

    DaThuc congHoacTru(const DaThuc& other, bool isCong = true) const {
        int maxBac = max(bac, other.bac); 
        DaThuc ketQua(maxBac);

        for (int i = 0; i <= maxBac; ++i) {
            double heSo1 = (i <= bac) ? heSo[i] : 0;
            double heSo2 = (i <= other.bac) ? other.heSo[i] : 0;
            ketQua.heSo[i] = heSo1 + (isCong ? heSo2 : -heSo2);
        }

        return ketQua;
    }

    DaThuc cong(const DaThuc& other) const {
        return congHoacTru(other, true);
    }

    DaThuc tru(const DaThuc& other) const {
        return congHoacTru(other, false);
    }
};

int main() {
    int n;

    cout << "Nhap bac cua da thuc thu nhat:\n";
    cin >> n;
    DaThuc dt1(n);
    dt1.nhap();

    cout << "Nhap bac cua da thuc thu hai:\n";
    cin >> n;
    DaThuc dt2(n);
    dt2.nhap();

    cout << "Da thuc thu nhat: ";
    dt1.xuat();

    cout << "Da thuc thu hai: ";
    dt2.xuat();

    DaThuc tong = dt1.cong(dt2);
    cout << "Tong 2 da thuc: ";
    tong.xuat();

    DaThuc hieu = dt1.tru(dt2);
    cout << "Hieu 2 da thuc: ";
    hieu.xuat();

    return 0;
}
