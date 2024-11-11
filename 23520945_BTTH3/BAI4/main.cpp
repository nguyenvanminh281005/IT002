#include "bai4.h"

int main() {
    NgayThangNam ngay1, ngay2;

    cout << "Nhap ngay1:" << endl;
    cin >> ngay1;

    cout << "Nhap ngay2:" << endl;
    cin >> ngay2;

    cout << "Ngay1: " << ngay1 << endl;
    cout << "Ngay2: " << ngay2 << endl;

    ngay2 = ngay2 + 5;
    cout << "Ngay2 sau khi cong 5 ngay: " << ngay2 << endl;

    ngay2 = ngay2 - 3;
    cout << "Ngay2 sau khi tru 3 ngay: " << ngay2 << endl;

    if (ngay1 == ngay2) {
        cout << "Ngay1 bang ngay2" << endl;
    } else {
        cout << "Ngay1 khong bang ngay2" << endl;
    }

    return 0;
}
