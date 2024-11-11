#include <iostream>
#include <vector>
using namespace std;

// Lớp cơ sở CanBo
class CanBo {
protected:
    string maCanBo;
    string hoTen;
    string gioiTinh;

public:
    // Hàm nhập thông tin cán bộ
    void nhapThongTin() {
        cout << "Nhap ma can bo: ";
        cin >> maCanBo;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap gioi tinh: ";
        cin >> gioiTinh;
    }

    // Hàm hiển thị thông tin cán bộ
    virtual void hienThiThongTin() {
        cout << "Ma can bo: " << maCanBo << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
    }

    // Hàm tính lương (hàm ảo)
    virtual double tinhLuong() = 0;
};

// Lớp GiangVien kế thừa từ CanBo
class GiangVien : public CanBo {
private:
    int soGioDay;
    int soGioNghienCuu;
    double donGia;

public:
    // Hàm nhập thông tin giảng viên
    void nhapThongTin() {
        CanBo::nhapThongTin();
        cout << "Nhap so gio day: ";
        cin >> soGioDay;
        cout << "Nhap so gio nghien cuu: ";
        cin >> soGioNghienCuu;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    // Hàm tính lương giảng viên
    double tinhLuong() override {
        return (soGioDay + soGioNghienCuu) * donGia;
    }

    // Hàm hiển thị thông tin giảng viên
    void hienThiThongTin() override {
        CanBo::hienThiThongTin();
        cout << "So gio day: " << soGioDay << endl;
        cout << "So gio nghien cuu: " << soGioNghienCuu << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
};

// Lớp NhanVienHanhChinh kế thừa từ CanBo
class NhanVienHanhChinh : public CanBo {
private:
    int soNgayLamViec;
    int soGioLamThem;
    double tienCongNgay;
    double donGia;

public:
    // Hàm nhập thông tin nhân viên hành chính
    void nhapThongTin() {
        CanBo::nhapThongTin();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cout << "Nhap so gio lam them: ";
        cin >> soGioLamThem;
        cout << "Nhap tien cong 1 ngay: ";
        cin >> tienCongNgay;
        cout << "Nhap don gia lam them: ";
        cin >> donGia;
    }

    // Hàm tính lương nhân viên hành chính
    double tinhLuong() override {
        return soNgayLamViec * tienCongNgay + soGioLamThem * donGia;
    }

    // Hàm hiển thị thông tin nhân viên hành chính
    void hienThiThongTin() override {
        CanBo::hienThiThongTin();
        cout << "So ngay lam viec: " << soNgayLamViec << endl;
        cout << "So gio lam them: " << soGioLamThem << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
};

int main() {
    vector<CanBo*> danhSachCanBo;
    int luaChon;

    do {
        cout << "\n--- Quan ly can bo ---\n";
        cout << "1. Them giang vien\n";
        cout << "2. Them nhan vien hanh chinh\n";
        cout << "3. Hien thi thong tin tat ca can bo\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            GiangVien* gv = new GiangVien();
            gv->nhapThongTin();
            danhSachCanBo.push_back(gv);
        } else if (luaChon == 2) {
            NhanVienHanhChinh* nv = new NhanVienHanhChinh();
            nv->nhapThongTin();
            danhSachCanBo.push_back(nv);
        } else if (luaChon == 3) {
            cout << "\n--- Danh sach can bo ---\n";
            for (auto canBo : danhSachCanBo) {
                canBo->hienThiThongTin();
            }
        }
    } while (luaChon != 0);

    // Giải phóng bộ nhớ
    for (auto canBo : danhSachCanBo) {
        delete canBo;
    }

    cout << "Chuong trinh ket thuc.\n";
    return 0;
}

