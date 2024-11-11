#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
    string maHS;
    string hoTen;
    string gioiTinh;
    float diemToan, diemLy, diemHoa;
};

float tinhDiemTrungBinh(HocSinh hs) {
    return (hs.diemToan + hs.diemLy + hs.diemHoa) / 3;
}

int main() {
    HocSinh hs;

    cout << "Nhap ma hoc sinh: ";
    cin >> hs.maHS;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hs.hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, hs.gioiTinh);
    cout << "Nhap diem Toan: ";
    cin >> hs.diemToan;
    cout << "Nhap diem Ly: ";
    cin >> hs.diemLy;
    cout << "Nhap diem Hoa: ";
    cin >> hs.diemHoa;

    float dtb = tinhDiemTrungBinh(hs);
    cout << "Diem trung binh: " << dtb << endl;
    cout << "Thong tin hoc sinh: " << endl;
    cout << "Ma: " << hs.maHS << ", Ho ten: " << hs.hoTen << ", Gioi tinh: " << hs.gioiTinh << endl;

    return 0;
}
