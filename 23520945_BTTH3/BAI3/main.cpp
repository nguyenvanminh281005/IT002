#include <iostream>
#include "bai3.h"
using namespace std;
int main() {
    ThoiGian tg1, tg2;
//    input
    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;
    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;

//    tinh toan
    ThoiGian tong = tg1 + tg2;
    ThoiGian hieu = tg1 - tg2;

    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;

//    check tang giam
    ++tg1;
    cout << "tg1 sau khi ++: " << tg1 << endl;

    --tg2;
    cout << "tg2 sau khi --: " << tg2 << endl;

//    so sanh
    if (tg1 > tg2) {
        cout << "tg1 lon hon tg2" << endl;
    } else {
        cout << "tg1 khong lon hon tg2" << endl;
    }

    return 0;
}
