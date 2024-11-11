#include <iostream>
#include <vector>
using namespace std;

// Class representing a fraction
class PhanSo {
public:
    int tu, mau; // Numerator and denominator

    PhanSo(int tu = 0, int mau = 1) {
        this->tu = tu;
        this->mau = (mau == 0) ? 1 : mau; // Prevent division by zero
        rutGon();
    }

    // Function to simplify the fraction
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void rutGon() {
        int gcdValue = gcd(abs(tu), abs(mau));
        tu /= gcdValue;
        mau /= gcdValue;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Overloading addition operator
    PhanSo operator+(const PhanSo& other) const {
        PhanSo result;
        result.tu = tu * other.mau + mau * other.tu;
        result.mau = mau * other.mau;
        result.rutGon();
        return result;
    }

    // Overloading equality operator to compare two fractions
    bool operator==(const PhanSo& other) const {
        return tu == other.tu && mau == other.mau;
    }

    // Output the fraction
    void Xuat() const {
        cout << tu << "/" << mau << endl;
    }
};

// Function to find subsets of fractions that sum up to a target fraction
void timTapCon(const vector<PhanSo>& arr, const PhanSo& target) {
    int n = arr.size();
    bool found = false;

    // Using a bitmask to find all subsets
    for (int mask = 1; mask < (1 << n); ++mask) {
        PhanSo sum; // Starting sum with 0/1

        cout << "Tap con: ";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum = sum + arr[i];
                arr[i].Xuat();
            }
        }

        // If the subset sum matches the target fraction
        if (sum == target) {
            cout << " -> Tong bang phan so dich." << endl;
            found = true;
        } else {
            cout << " -> Khong bang phan so dich." << endl;
        }
    }

    if (!found) {
        cout << "Khong co tap con nao co tong bang phan so dich." << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> arr(n);
    cout << "Nhap danh sach cac phan so: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap tu so thu " << i + 1 << ": ";
        cin >> arr[i].tu;
        cout << "Nhap mau so thu " << i + 1 << ": ";
        cin >> arr[i].mau;
        arr[i].rutGon();
    }
    
    PhanSo phanSoDich;
    cout << "Nhap phan so dich: " << endl;
    cout << "Nhap tu so dich: ";
    cin >> phanSoDich.tu;
    cout << "Nhap mau so dich: ";
    cin >> phanSoDich.mau;

    phanSoDich.rutGon();

    timTapCon(arr, phanSoDich);

    return 0;
}
