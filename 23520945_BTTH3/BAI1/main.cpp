#include <iostream>
#include "bai1.h"

int main() {
    PhanSo a, b;

    // Input two fractions
    std::cout << "Nhap phan so a:\n";
    std::cin >> a;
    std::cout << "Nhap phan so b:\n";
    std::cin >> b;

    // Perform operations
    PhanSo tong = a + b;
    PhanSo hieu = a - b;
    PhanSo tich = a * b;
    PhanSo thuong = a / b;

    // Output results
    std::cout << "Tong: " << tong << std::endl;
    std::cout << "Hieu: " << hieu << std::endl;
    std::cout << "Tich: " << tich << std::endl;
    std::cout << "Thuong: " << thuong << std::endl;

    // Comparison
    if (a == b) std::cout << "Bang nhau" << std::endl;
    if (a != b) std::cout << "Khac nhau" << std::endl;
    if (a < b) std::cout << "Be hon" << std::endl;
    if (a > b) std::cout << "Lon hon" << std::endl;

    return 0;
}
