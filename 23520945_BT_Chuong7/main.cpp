#include <iostream>
#include "nv.cpp"
#include <vector>
using namespace std;

int main() {
    vector<NhanVien*> danhSachNhanVien;
    int soNhanVien;
    cout << "Nhap so luong nhan vien: ";
    cin >> soNhanVien;
    cin.ignore(); // Bỏ qua ký tự xuống dòng

    for (int i = 0; i < soNhanVien; i++) {
        cout << "Nhap thong tin cho nhan vien thu " << (i + 1) << ":" << endl;

        string hoTen, ngaySinh;
        double luongCoBan;
        int loaiNhanVien;

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;

        cout << "Chon loai nhan vien (1 - Van phong, 2 - San xuat, 3 - Quan ly): ";
        cin >> loaiNhanVien;

        cin.ignore(); // Bỏ qua ký tự xuống dòng

        if (loaiNhanVien == 1) {
            int soNgayLamViec;
            double troCap;

            cout << "Nhap so ngay lam viec: ";
            cin >> soNgayLamViec;
            cout << "Nhap tro cap: ";
            cin >> troCap;
            cin.ignore(); // Bỏ qua ký tự xuống dòng

            // Thêm nhân viên văn phòng vào danh sách
            danhSachNhanVien.push_back(new NhanVienVanPhong(hoTen, ngaySinh, luongCoBan, soNgayLamViec, troCap));

        } else if (loaiNhanVien == 2) {
            int soSanPham;

            cout << "Nhap so san pham: ";
            cin >> soSanPham;
            cin.ignore(); // Bỏ qua ký tự xuống dòng

            // Thêm nhân viên sản xuất vào danh sách
            danhSachNhanVien.push_back(new NhanVienSanXuat(hoTen, ngaySinh, luongCoBan, soSanPham));

        } else if (loaiNhanVien == 3) {
            double heSoChucVu, thuong;

            cout << "Nhap he so chuc vu: ";
            cin >> heSoChucVu;
            cout << "Nhap thuong: ";
            cin >> thuong;
            cin.ignore(); // Bỏ qua ký tự xuống dòng

            // Thêm nhân viên quản lý vào danh sách
            danhSachNhanVien.push_back(new NhanVienQuanLy(hoTen, ngaySinh, luongCoBan, heSoChucVu, thuong));

        } else {
            cout << "Loai nhan vien khong hop le!" << endl;
        }
    }

    // Xuất thông tin nhân viên
    cout << "\nDanh sach nhan vien:" << endl;
    for (NhanVien* nv : danhSachNhanVien) {
        nv->xuatThongTin();
        cout << "-----------------------------" << endl;
    }

    // Tính tổng lương của công ty
    double tongLuong = 0;
    for (NhanVien* nv : danhSachNhanVien) {
        tongLuong += nv->tinhLuong();
    }
    cout << "Tong luong cua cong ty: " << tongLuong << endl;

    // Tìm kiếm nhân viên theo họ tên
    string hoTenTimKiem;
    cout << "\nNhap ho ten nhan vien can tim: ";
    getline(cin, hoTenTimKiem);

    bool timThay = false;
    for (NhanVien* nv : danhSachNhanVien) {
        if (nv->getHoTen() == hoTenTimKiem) {
            cout << "Da tim thay nhan vien:" << endl;
            nv->xuatThongTin();
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay nhan vien co ten: " << hoTenTimKiem << endl;
    }

    // Giải phóng bộ nhớ
    for (NhanVien* nv : danhSachNhanVien) {
        delete nv;
    }

    return 0;
}
