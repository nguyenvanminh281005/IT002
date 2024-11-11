#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau; // numerator and denominator
public:
    // Constructor
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = (mau == 0) ? 1 : mau; // Avoid division by 0
    }

    // Function to simplify a fraction
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void simplify() {
        int GCD = gcd(abs(tu), abs(mau));
        tu /= GCD;
        mau /= GCD;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Input and Output functions
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) mau = 1; // Avoid division by 0
        simplify();
    }

    void Xuat() {
        cout << tu << "/" << mau << endl;
    }

    // Comparison operator to find the larger/smaller fraction
    bool operator>(const PhanSo &ps) {
        return tu * ps.mau > mau * ps.tu;
    }

    bool operator<(const PhanSo &ps) {
        return tu * ps.mau < mau * ps.tu;
    }
};

class arrPhanSo {
private:
    PhanSo *arr;
    int size;
public:
    // Constructor
    arrPhanSo() {
        arr = nullptr;
        size = 0;
    }

    ~arrPhanSo() {
        delete[] arr;
    }

    // Function to input fractions
    void nhap(int n) {
        size = n;
        arr = new PhanSo[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan so thu " << i + 1 << ": " << endl;
            arr[i].Nhap();
        }
    }

    // Function to get the largest fraction
    PhanSo LayPSLonNhat() {
        PhanSo max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Function to get the smallest fraction
    PhanSo LayPSNhoNhat() {
        PhanSo min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
};

int main() {
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;

    arrPhanSo a;
    a.nhap(n);

    cout << "Phan so lon nhat la: " << endl;
    a.LayPSLonNhat().Xuat();

    cout << "Phan so nho nhat la: " << endl;
    a.LayPSNhoNhat().Xuat();

    return 0;
}
