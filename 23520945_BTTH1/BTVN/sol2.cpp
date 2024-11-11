#include <iostream>
#include <algorithm>  // for sort function
#include <vector>     // for vector
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
    bool operator>(const PhanSo &ps) const {
        return tu * ps.mau > mau * ps.tu;
    }

    bool operator<(const PhanSo &ps) const {
        return tu * ps.mau < mau * ps.tu;
    }
};

class arrPhanSo {
private:
    vector<PhanSo> arr;
public:
    // Function to input fractions
    void nhap(int n) {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan so thu " << i + 1 << ": " << endl;
            arr[i].Nhap();
        }
    }

    // Function to find the k-th largest fraction
    void LayPSLonThu(int k) {
        if (k > 0 && k <= arr.size()) {
            sort(arr.begin(), arr.end(), greater<PhanSo>()); // Sort in descending order
            cout << "Phan so lon thu " << k << " la: ";
            arr[k-1].Xuat();
        } else {
            cout << "Gia tri k khong hop le!" << endl;
        }
    }

    // Function to find the k-th smallest fraction
    void LayPSNhoThu(int k) {
        if (k > 0 && k <= arr.size()) {
            sort(arr.begin(), arr.end()); // Sort in ascending order
            cout << "Phan so nho thu " << k << " la: ";
            arr[k-1].Xuat();
        } else {
            cout << "Gia tri k khong hop le!" << endl;
        }
    }
};

int main() {
    int n, k;
    
    cout << "Nhap so phan so: ";
    cin >> n;
    arrPhanSo a;
    a.nhap(n);
    
    cout << "Nhap k de tim phan so lon thu k: ";
    cin >> k;
    a.LayPSLonThu(k);
    
    cout << "Nhap k de tim phan so nho thu k: ";
    cin >> k;
    a.LayPSNhoThu(k);

    return 0;
}
