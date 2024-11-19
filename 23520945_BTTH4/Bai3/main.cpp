#include <iostream>
#include <vector>
#include "bai3.h"

using namespace std;

int main() {
    int SoLuongBo, SoLuongCuu, SoLuongDe;

    // Nhập số lượng gia súc ban đầu
    cout << "Nhap so luong bo ban dau: ";
    cin >> SoLuongBo;
    cout << "Nhap so luong cuu ban dau: ";
    cin >> SoLuongCuu;
    cout << "Nhap so luong de ban dau: ";
    cin >> SoLuongDe;

    // Tạo các đối tượng gia súc
    Bo DanBo(SoLuongBo);
    Cuu DanCuu(SoLuongCuu);
    De DanDe(SoLuongDe);

    // Phần a: Gia súc đói kêu
    cout << "\nTieng keu trong nong trai: \n";
    for (int i = 0; i < DanBo.LaySoLuong(); ++i) cout << DanBo.KeuLen() << " ";
    for (int i = 0; i < DanCuu.LaySoLuong(); ++i) cout << DanCuu.KeuLen() << " ";
    for (int i = 0; i < DanDe.LaySoLuong(); ++i) cout << DanDe.KeuLen() << " ";
    cout << "\n";

    // Phần b: Thống kê sau 1 lứa sinh con và 1 lượt cho sữa
    int TongSoSua = 0;

    // Thống kê cho Bò
    int SuaBo = 0;
    for (int i = 0; i < DanBo.LaySoLuong(); ++i) {
        SuaBo += DanBo.ChoSua();
    }
    TongSoSua += SuaBo;

    int SoConBo = 0;
    for (int i = 0; i < DanBo.LaySoLuong(); ++i) {
        SoConBo += DanBo.SinhCon();
    }
    DanBo.ThemSoLuong(SoConBo);

    // Thống kê cho Cừu
    int SuaCuu = 0;
    for (int i = 0; i < DanCuu.LaySoLuong(); ++i) {
        SuaCuu += DanCuu.ChoSua();
    }
    TongSoSua += SuaCuu;

    int SoConCuu = 0;
    for (int i = 0; i < DanCuu.LaySoLuong(); ++i) {
        SoConCuu += DanCuu.SinhCon();
    }
    DanCuu.ThemSoLuong(SoConCuu);

    // Thống kê cho Dê
    int SuaDe = 0;
    for (int i = 0; i < DanDe.LaySoLuong(); ++i) {
        SuaDe += DanDe.ChoSua();
    }
    TongSoSua += SuaDe;

    int SoConDe = 0;
    for (int i = 0; i < DanDe.LaySoLuong(); ++i) {
        SoConDe += DanDe.SinhCon();
    }
    DanDe.ThemSoLuong(SoConDe);

    // In thống kê
    cout << "\nThong ke sau 1 lua sinh va cho sua\n";
    cout << "Bo: " << DanBo.LaySoLuong() << " (Sua: " << SuaBo << " lit)\n";
    cout << "Cuu: " << DanCuu.LaySoLuong() << " (Sua: " << SuaCuu << " lit)\n";
    cout << "De: " << DanDe.LaySoLuong() << " (Sua: " << SuaDe << " lit)\n";
    cout << "Tong luong sua: " << TongSoSua << " lit\n";

    return 0;
}