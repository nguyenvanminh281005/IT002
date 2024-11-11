#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tuso;
    int mauso;

    void rutGon() {
        int gcd = __gcd(abs(tuso), abs(mauso));
        tuso /= gcd;
        mauso /= gcd;

        if (mauso < 0) {
            tuso = -tuso;
            mauso = -mauso;
        }
    }

public:
    PhanSo(int tu = 0, int mau = 1) : tuso(tu), mauso(mau) {
        if (mau == 0) {
            throw invalid_argument("Mau so khong the bang 0.");
        }
        rutGon();
    }

    int LayTu() const {
        return tuso;
    }

    int LayMau() const {
        return mauso;
    }

    void GanTu(int t) {
        tuso = t;
        rutGon();
    }

    void GanMau(int m) {
        if (m == 0) {
            throw invalid_argument("Mau so khong the bang 0.");
        }
        mauso = m;
        rutGon();
    }

    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuso;
        cout << "Nhap mau so: ";
        cin >> mauso;
        while (mauso == 0) {
            cout << "Mau khong the bang 0, nhap lai mau so: ";
            cin >> mauso;
        }
        rutGon();
    }

    void Xuat() const {
        if (mauso == 1) {
            cout << tuso;
        } else {
            cout << tuso << "/" << mauso;
        }
        cout << endl;
    }

    bool operator>(const PhanSo &ps) const {
        return (double)tuso / mauso > (double)ps.tuso / ps.mauso;
    }

    PhanSo operator+(const PhanSo &ps) const {
        int tu = tuso * ps.mauso + mauso * ps.tuso;
        int mau = mauso * ps.mauso;
        return PhanSo(tu, mau);
    }

    PhanSo operator-(const PhanSo &ps) const {
        int tu = tuso * ps.mauso - mauso * ps.tuso;
        int mau = mauso * ps.mauso;
        return PhanSo(tu, mau);
    }
};

class arrPhanSo {
private:
    vector<PhanSo> arr;

public:
    void nhap(int n) {
        arr.clear();
        for (int i = 0; i < n; ++i) {
            PhanSo ps;
            cout << "Nhap phan so thu " << i + 1 << ":\n";
            ps.Nhap();
            arr.push_back(ps);
        }
    }

    void xuat() const {
        for (const PhanSo &ps : arr) {
            ps.Xuat();
            cout << " ";
        }
        cout << endl;
    }

    PhanSo LayPS(int i) const {
        if (i >= 0 && i < arr.size()) {
            return arr[i];
        }
        throw out_of_range("Chi so khong hop le.");
    }

    PhanSo LayPSLonNhat() const {
        if (arr.empty()) {
            throw length_error("Danh sach phan so rong.");
        }

        PhanSo psmax = arr[0];
        for (const PhanSo &ps : arr) {
            if (ps > psmax) {
                psmax = ps;
            }
        }
        return psmax;
    }
};

int main() {
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;

    arrPhanSo a;
    a.nhap(n);

    cout << "Phan so lon nhat la: ";
    a.LayPSLonNhat().Xuat();

    return 0;
}
