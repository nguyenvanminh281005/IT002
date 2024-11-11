#include <bits/stdc++.h>
using namespace std;

class cArray {
private:
    vector<int> arr;

public:
    void input(int n) {
        arr.resize(n);
        cout << "Nhap " << n << " phan tu:" << endl;
        for (auto &num : arr) {
            cin >> num;
        }
    }

    void output() const {
        for (const auto &num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void random(int n, int low = 0, int hi = 100) {
        arr.resize(n);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(low, hi);
        for (auto &num : arr) {
            num = dist(gen);
        }
    }

    int count(int x) const {
        return std::count(arr.begin(), arr.end(), x);
    }

    bool isAscending() const {
        return std::is_sorted(arr.begin(), arr.end());
    }

    int minOdd() const {
        int min_odd = INT_MAX;
        for (const auto &num : arr) {
            if (num % 2 != 0 && num < min_odd) {
                min_odd = num;
            }
        }
        return (min_odd == INT_MAX) ? -1 : min_odd;
    }

    void sortAscending() {
        if (!isAscending()) {
            std::sort(arr.begin(), arr.end());
        }
    }
};

int main() {
    cArray arr;
    int n, x;

    cout << "Nhap vao so phan tu: ";
    cin >> n;
    arr.input(n);
    cout << "Cac phan tu trong arr la: ";
    arr.output();

    cout << "Xoa array va random " << n << " phan tu:" << endl;
    arr.random(n);
    arr.output();

    cout << "Nhap so can dem: ";
    cin >> x;
    cout << x << " xuat hien " << arr.count(x) << " lan" << endl;

    if (arr.isAscending())
        cout << "Day tang dan" << endl;
    else
        cout << "Day khong tang dan" << endl;

    int min_odd = arr.minOdd();
    if (min_odd != -1)
        cout << "Gia tri le nho nhat la: " << min_odd << endl;
    else
        cout << "Khong co gia tri le trong day." << endl;

    cout << "Sap xep day tang dan" << endl;
    arr.sortAscending();
    cout << "Day moi la: ";
    arr.output();

    return 0;
}