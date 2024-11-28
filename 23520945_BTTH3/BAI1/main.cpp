#include <iostream>
#include "bai1.h"
using namespace std;
int main() {
    PhanSo a, b;
//    nhap so vao
    cout << "Nhap phan so a:\n";
    cin >> a;
    cout << "Nhap phan so b:\n";
    cin >> b;
//    tinh toan
    PhanSo tong = a + b;
    PhanSo hieu = a - b;
    PhanSo tich = a * b;
    PhanSo thuong = a / b;
//  cout ra
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout << "Thuong: " << thuong << endl;
    
    if (a == b) cout << "Bang nhau" << endl;
    if (a != b) cout << "Khac nhau" << endl;
    if (a < b) cout << "Be hon" << endl;
    if (a > b) cout << "Lon hon" << endl;

    return 0;
}
