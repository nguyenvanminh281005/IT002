#include <iostream>
#include "bai2.h"

int main() {
    SoPhuc a, b;

    // Nhập hai số phức
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
    cin >> b;

    // Thực hiện các phép toán
    SoPhuc tong = a + b;
    SoPhuc hieu = a - b;
    SoPhuc tich = a * b;
    SoPhuc thuong;

    try {
        thuong = a / b;
    } catch (const invalid_argument& e) {
        cout << "Loi: " << e.what() << endl;
    }

    // Xuất kết quả
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    if (b.dthuc != 0 || b.dao != 0) {
        cout << "Thuong: " << thuong << endl;
    }

    // So sánh
    if (a == b) {
        cout << "Hai so phuc bang nhau" << endl;
    } else {
        cout << "Hai so phuc khac nhau" << endl;
    }

    return 0;
}
