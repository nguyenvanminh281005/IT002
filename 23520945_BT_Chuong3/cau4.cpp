#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<lli> dist(-1e6, 1e6);

lli getRandom(lli L, lli R) {
    return dist(gen) % (R - L + 1) + L;
}

struct cArray {
    int n;
    vector<int> arr;

    cArray() {}
    cArray(int _n) : n(_n) {
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i] = getRandom(-1e6, 1e6);
        }
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int findMaxNeg() const {
        int maxNeg = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0 && arr[i] > maxNeg) {
                maxNeg = arr[i];
            }
        }
        return maxNeg;
    }

    int cnt(int x) const {
        return count(arr.begin(), arr.end(), x);
    }

    bool isDescending() const {
        return is_sorted(arr.rbegin(), arr.rend());
    }

    void sortAscending() {
        sort(arr.begin(), arr.end());
    }
};

int main() {
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;

    cArray arr(n);

    cout << "Mang da duoc random la: ";
    arr.print();

    int maxNeg = arr.findMaxNeg();
    if (maxNeg == INT_MIN) {
        cout << "Mang khong co so am" << endl;
    } else {
        cout << "So am lon nhat trong mang: " << maxNeg << endl;
    }

    int x;
    cout << "Nhap so can dem so lan xuat hien: ";
    cin >> x;
    int cnt = arr.cnt(x);
    cout << "So " << x << " xuat hien " << cnt << " lan" << endl;

    if (arr.isDescending()) {
        cout << "Mang duoc sap xep giam dan." << endl;
    } else {
        cout << "Mang khong duoc sap xep giam dan." << endl;
    }

    arr.sortAscending();
    cout << "Mang sau khi duoc sap xep tang dan: ";
    arr.print();

    return 0;
}
