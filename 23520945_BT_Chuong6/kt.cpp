#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở SinhVien
class SinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTrungBinh;

public:
    // Hàm nhập thông tin sinh viên
    void nhapThongTin() {
        cout << "Nhap ma so sinh vien: ";
        cin >> maSV;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap tong so tin chi: ";
        cin >> tongTinChi;
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
    }

    // Hàm ảo kiểm tra tốt nghiệp
    virtual bool kiemTraTotNghiep() = 0;

    // Hàm ảo xuất thông tin
    virtual void xuatThongTin() = 0;
};

// Lớp SinhVienCaoDang kế thừa từ SinhVien
class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTotNghiep;

public:
    // Hàm nhập thông tin sinh viên cao đẳng
    void nhapThongTin() {
        SinhVien::nhapThongTin();
        cout << "Nhap diem thi tot nghiep: ";
        cin >> diemThiTotNghiep;
    }

    // Kiểm tra điều kiện tốt nghiệp sinh viên cao đẳng
    bool kiemTraTotNghiep() override {
        return tongTinChi >= 120 && diemTrungBinh >= 5.0 && diemThiTotNghiep >= 5.0;
    }

    // Xuất thông tin sinh viên cao đẳng
    void xuatThongTin() override {
        cout << "Ma so sinh vien: " << maSV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong so tin chi: " << tongTinChi << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
        cout << "Diem thi tot nghiep: " << diemThiTotNghiep << endl;
        cout << "Ket qua tot nghiep: " << (kiemTraTotNghiep() ? "Dat" : "Khong dat") << endl;
    }
};

// Lớp SinhVienDaiHoc kế thừa từ SinhVien
class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    // Hàm nhập thông tin sinh viên đại học
    void nhapThongTin() {
        SinhVien::nhapThongTin();
        cout << "Nhap ten luan van: ";
        cin.ignore();
        getline(cin, tenLuanVan);
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;
    }

    // Kiểm tra điều kiện tốt nghiệp sinh viên đại học
    bool kiemTraTotNghiep() override {
        return tongTinChi >= 170 && diemTrungBinh >= 5.0 && diemLuanVan >= 5.0;
    }

    // Xuất thông tin sinh viên đại học
    void xuatThongTin() override {
        cout << "Ma so sinh vien: " << maSV << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong so tin chi: " << tongTinChi << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
        cout << "Ten luan van: " << tenLuanVan << endl;
        cout << "Diem luan van: " << diemLuanVan << endl;
        cout << "Ket qua tot nghiep: " << (kiemTraTotNghiep() ? "Dat" : "Khong dat") << endl;
    }
};

int main() {
    SinhVienCaoDang svCaoDang;
    SinhVienDaiHoc svDaiHoc;

    cout << "Nhap thong tin sinh vien cao dang:\n";
    svCaoDang.nhapThongTin();

    cout << "\nNhap thong tin sinh vien dai hoc:\n";
    svDaiHoc.nhapThongTin();

    cout << "\nThong tin sinh vien cao dang:\n";
    svCaoDang.xuatThongTin();

    cout << "\nThong tin sinh vien dai hoc:\n";
    svDaiHoc.xuatThongTin();

    return 0;
}
