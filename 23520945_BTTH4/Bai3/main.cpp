#include <iostream>
#include <vector>
#include "bai3.h"

using namespace std;

int main() {
    int SoLuongBo, SoLuongCuu, SoLuongDe;

    cout << "Nhap so luong bo ban dau: ";
    cin >> SoLuongBo;
    cout << "Nhap so luong cuu ban dau: ";
    cin >> SoLuongCuu;
    cout << "Nhap so luong de ban dau: ";
    cin >> SoLuongDe;

    Bo DanBo(SoLuongBo);
    Cuu DanCuu(SoLuongCuu);
    De DanDe(SoLuongDe);

    cout << "\nTieng keu trong nong trai: \n";
    for (int i = 0; i < DanBo.LaySoLuong(); ++i) cout << DanBo.KeuLen() << " ";
    for (int i = 0; i < DanCuu.LaySoLuong(); ++i) cout << DanCuu.KeuLen() << " ";
    for (int i = 0; i < DanDe.LaySoLuong(); ++i) cout << DanDe.KeuLen() << " ";
    cout << "\n";

    int TongSoSua = 0;

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
    
    cout << "\nThong ke sau 1 lua sinh va cho sua\n";
    cout << "Bo: " << DanBo.LaySoLuong() << " (Sua: " << SuaBo << " lit)\n";
    cout << "Cuu: " << DanCuu.LaySoLuong() << " (Sua: " << SuaCuu << " lit)\n";
    cout << "De: " << DanDe.LaySoLuong() << " (Sua: " << SuaDe << " lit)\n";
    cout << "Tong luong sua: " << TongSoSua << " lit\n";

    return 0;
}