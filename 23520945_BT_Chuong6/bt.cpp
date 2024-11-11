#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    double luongCoBan;

public:
    // Hàm nhập thông tin nhân viên
    virtual void nhapThongTin() {
        cout << "Nhap ma nhan vien: ";
        cin >> maNV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap so dien thoai: ";
        cin >> soDienThoai;
        cout << "Nhap email: ";
        cin >> email;
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
    }

    // Hàm tính lương (hàm ảo)
    virtual double tinhLuong() = 0;

    // Hàm ảo xuất thông tin nhân viên
    virtual void xuatThongTin() {
        cout << "Ma nhan vien: " << maNV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "So dien thoai: " << soDienThoai << endl;
        cout << "Email: " << email << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Luong thang: " << tinhLuong() << endl;
    }
};

// Lớp LapTrinhVien kế thừa từ NhanVien
class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    // Hàm nhập thông tin lập trình viên
    void nhapThongTin() override {
        NhanVien::nhapThongTin();
        cout << "Nhap so gio overtime: ";
        cin >> soGioOvertime;
    }

    // Tính lương lập trình viên
    double tinhLuong() override {
        return luongCoBan + soGioOvertime * 200000;
    }

    // Xuất thông tin lập trình viên
    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "So gio overtime: " << soGioOvertime << endl;
    }
};

// Lớp KiemChungVien kế thừa từ NhanVien
class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    // Hàm nhập thông tin kiểm chứng viên
    void nhapThongTin() override {
        NhanVien::nhapThongTin();
        cout << "Nhap so loi phat hien: ";
        cin >> soLoiPhatHien;
    }

    // Tính lương kiểm chứng viên
    double tinhLuong() override {
        return luongCoBan + soLoiPhatHien * 50000;
    }

    // Xuất thông tin kiểm chứng viên
    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "So loi phat hien: " << soLoiPhatHien << endl;
    }
};

int main() {
    vector<NhanVien*> danhSachNhanVien;
    int luaChon;
    int soNhanVien;
    double tongLuong = 0;

    // Nhập danh sách nhân viên
    cout << "Nhap so luong nhan vien: ";
    cin >> soNhanVien;

    for (int i = 0; i < soNhanVien; ++i) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        cout << "1. Lap trinh vien\n";
        cout << "2. Kiem chung vien\n";
        cout << "Lua chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            LapTrinhVien* ltv = new LapTrinhVien();
            ltv->nhapThongTin();
            danhSachNhanVien.push_back(ltv);
            tongLuong += ltv->tinhLuong();
        } else if (luaChon == 2) {
            KiemChungVien* kcv = new KiemChungVien();
            kcv->nhapThongTin();
            danhSachNhanVien.push_back(kcv);
            tongLuong += kcv->tinhLuong();
        }
    }

    // Tính lương trung bình
    double luongTrungBinh = tongLuong / soNhanVien;

    // Xuất danh sách nhân viên
    cout << "\n--- Danh sach nhan vien ---\n";
    for (auto nv : danhSachNhanVien) {
        nv->xuatThongTin();
        cout << "--------------------------\n";
    }

    // Liệt kê nhân viên có lương thấp hơn mức lương trung bình
    cout << "\n--- Danh sach nhan vien co luong thap hon luong trung binh (" << luongTrungBinh << ") ---\n";
    for (auto nv : danhSachNhanVien) {
        if (nv->tinhLuong() < luongTrungBinh) {
            nv->xuatThongTin();
            cout << "--------------------------\n";
        }
    }

    // Giải phóng bộ nhớ
    for (auto nv : danhSachNhanVien) {
        delete nv;
    }

    return 0;
}
