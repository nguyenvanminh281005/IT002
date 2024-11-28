#include <iostream>
#include "bai2.h"
using namespace std;
int main() {
    SoPhuc a, b;

    // nhap hai so phuc
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
    cin >> b;

//  tinh toan
    SoPhuc tong = a + b;
    SoPhuc hieu = a - b;
    SoPhuc tich = a * b;
    SoPhuc thuong;

    try {
        thuong = a / b;
    } catch (const invalid_argument& e) {
        cout << "Loi: " << e.what() << endl;
    }

//  cout kq
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    if (b.dthuc != 0 || b.dao != 0) {
        cout << "Thuong: " << thuong << endl;
    }

//  so sanh
    if (a == b) {
        cout << "Hai so phuc bang nhau" << endl;
    } else {
        cout << "Hai so phuc khac nhau" << endl;
    }

    return 0;
}
