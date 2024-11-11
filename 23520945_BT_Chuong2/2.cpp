#include <bits/stdc++.h>
#include <numeric>  // Thư viện chứa hàm gcd
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

// Hàm nhập phân số
PhanSo nhapPhanSo() {
    PhanSo ps;
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    cout << "Nhap mau so: ";
    cin >> ps.mau;
    return ps;
}

// Hàm tính tổng hai phân số
PhanSo tong(PhanSo a, PhanSo b) {
    PhanSo ketQua;
    ketQua.tu = a.tu * b.mau + b.tu * a.mau;
    ketQua.mau = a.mau * b.mau;
    return ketQua;
}

// Hàm rút gọn phân số
PhanSo rutGon(PhanSo ps) {
    int uc = __gcd(abs(ps.tu), abs(ps.mau));  // Sử dụng hàm gcd có sẵn
    ps.tu /= uc;
    ps.mau /= uc;
    return ps;
}

// Hàm xuất phân số đã rút gọn
void xuatPhanSo(PhanSo ps) {
    ps = rutGon(ps);  // Rút gọn trước khi xuất
    if (ps.mau == 1) {  // Nếu mẫu số là 1 thì chỉ xuất tử
        cout << ps.tu << endl;
    } else {
        cout << ps.tu << "/" << ps.mau << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> danhSach;
    for (int i = 0; i < n; i++) {
        PhanSo ps = nhapPhanSo();
        danhSach.push_back(ps);
    }

    PhanSo tongTatCa = {0, 1};  // Khởi tạo tổng là 0
    for (PhanSo ps : danhSach) {
        tongTatCa = tong(tongTatCa, ps);
    }

    cout << "Tong tat ca phan so: ";
    xuatPhanSo(tongTatCa);  // Xuất tổng sau khi rút gọn

    return 0;
}
