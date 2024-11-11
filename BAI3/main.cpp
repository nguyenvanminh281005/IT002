#include <iostream>
#include "bai3.h"

int main() {
    ThoiGian tg1, tg2;

    // Nhập thời gian
    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;
    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;

    // Thực hiện các phép toán
    ThoiGian tong = tg1 + tg2;
    ThoiGian hieu = tg1 - tg2;

    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;

    // Kiểm tra toán tử tăng, giảm
    ++tg1;
    cout << "tg1 sau khi ++: " << tg1 << endl;

    --tg2;
    cout << "tg2 sau khi --: " << tg2 << endl;

    // So sánh hai thời gian
    if (tg1 > tg2) {
        cout << "tg1 lon hon tg2" << endl;
    } else {
        cout << "tg1 khong lon hon tg2" << endl;
    }

    return 0;
}
