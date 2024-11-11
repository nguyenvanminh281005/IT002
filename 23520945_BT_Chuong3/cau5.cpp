#include <bits/stdc++.h>

using namespace std;

struct cHocsinh {
    string masv, hoten, gioitinh;
    int namsinh;
    double dtb;
    cHocsinh() {}
    void input() {
        cout << "Nhap ma sinh vien: "; cin >> masv;
        cin.ignore();
        cout << "Nhap ho va ten: "; getline(cin, hoten);
        cout << "Nhap gioi tinh: "; cin >> gioitinh;
        cout << "Nhap nam sinh: "; cin >> namsinh;
        cout << "Nhap diem trung binh: "; cin >> dtb;
    }

    void display() const {
        cout << "Ma sinh vien: " << masv << endl;
        cout << "Ho va ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Nam sinh: " << namsinh << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }
};

int main() {
    cHocsinh A, B;
    
    cout << "Nhap thong tin hoc sinh A:\n";
    A.input();
    cout << "\nNhap thong tin hoc sinh B:\n";
    B.input();
    cout << "\nThong tin hoc sinh A:\n";
    A.display();
    cout << "\nThong tin hoc sinh B:\n";
    B.display();
    if (A.dtb > B.dtb) 
        cout << "\nHoc sinh A co diem trung binh cao hon." << endl;
    else if (A.dtb < B.dtb) 
        cout << "\nHoc sinh B co diem trung binh cao hon." << endl;
    else 
        cout << "\nA va B co diem trung binh bang nhau." << endl;

    if (A.namsinh > B.namsinh) 
        cout << "Hoc sinh B lon tuoi hon." << endl;
    else if (A.namsinh < B.namsinh) 
        cout << "Hoc sinh A lon tuoi hon." << endl;
    else 
        cout << "A va B bang tuoi nhau." << endl;

    return 0;
}
