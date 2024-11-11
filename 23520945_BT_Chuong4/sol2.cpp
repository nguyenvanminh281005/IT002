#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tu, mau;

    void rutGon() {
        int gcd = __gcd(tu, mau);
        tu /= gcd;
        mau /= gcd;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

public:
    PhanSo(int tu = 0, int mau = 1) {
        if (mau == 0) {
            cout << "Mau khong the bang 0. Nhap lai mau: ";
            while (mau == 0) {
                cin >> mau;
            }
        }
        this->tu = tu;
        this->mau = mau;
        rutGon();
    }

    double giaTri() const {
        return static_cast<double>(tu) / mau;
    }

    void xuat() const {
        cout << tu << "/" << mau;
    }

    bool tuSoNguyenTo() const {
        int absTu = abs(tu);
        if (absTu < 2) return false;
        for (int i = 2; i <= sqrt(absTu); ++i) {
            if (absTu % i == 0) return false;
        }
        return true;
    }

    bool operator<(const PhanSo& other) const {
        return this->giaTri() < other.giaTri();
    }
};

class arrPhanSo {
private:
    vector<PhanSo> arr;

public:
    void nhap(int n) {
        arr.clear();
        int tu, mau;
        for (int i = 0; i < n; ++i) {
            cout << "Nhap tu so cua ps thu " << i + 1 << ": ";
            cin >> tu;
            cout << "Nhap mau so cua ps thu " << i + 1 << ": ";
            cin >> mau;
            while (mau == 0) {
                cout << "Mau khong the bang 0, hay nhap lai: ";
                cin >> mau;
            }
            arr.push_back(PhanSo(tu, mau));
        }
    }

    void xuat() const {
        for (const auto& ps : arr) {
            ps.xuat();
            cout << " ";
        }
        cout << endl;
    }

    void random(int n, int low = 1, int hi = 100) {
        arr.clear();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(low, hi);

        for (int i = 0; i < n; ++i) {
            int tu = dist(gen);
            int mau = dist(gen);
            arr.push_back(PhanSo(tu, mau));
        }
    }

    PhanSo max() const {
        return *max_element(arr.begin(), arr.end(), [](const PhanSo& ps1, const PhanSo& ps2) {
            return ps1 < ps2;
        });
    }

    int demTuSoNguyenTo() const {
        return count_if(arr.begin(), arr.end(), [](const PhanSo& ps) {
            return ps.tuSoNguyenTo();
        });
    }

    void sortAscending() {
        sort(arr.begin(), arr.end());
    }
};

int main() {
    arrPhanSo arr_ps;
    int n;

    cout << "Nhap so phan so: ";
    cin >> n;
    arr_ps.nhap(n);
    cout << "Day phan so la: ";
    arr_ps.xuat();

    cout << "Day phan so ngau nhien la: ";
    arr_ps.random(n);
    arr_ps.xuat();

    cout << "Phan so co gia tri lon nhat la: ";
    arr_ps.max().xuat();
    cout << endl;

    int sopsnguyento = arr_ps.demTuSoNguyenTo();
    cout << "So phan so co tu so la so nguyen to la: " << sopsnguyento << endl;

    arr_ps.sortAscending();
    cout << "Cac phan so sau khi sap xep tang dan: ";
    arr_ps.xuat();

    return 0;
}