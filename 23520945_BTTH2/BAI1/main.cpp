#include <iostream>
#include "bai1.h"
using namespace std;

int main() {
    // Create a Diem object
    Diem d1;  // Default constructor

    // Get input from the user
    double hoanh, tung;
    cout << "Enter the coordinates for the point (x y): ";
    cin >> hoanh >> tung; // Read x and y coordinates from user input

    // Set the coordinates using the setter methods
    d1.SetHoanhDo(hoanh);
    d1.SetTungDo(tung);

    // Display the point
    cout << "Point d1: ";
    d1.Xuat();

    // Move point d1 by some units
    double dx, dy;
    cout << "Enter the translation values (dx dy): ";
    cin >> dx >> dy; // Read translation values from user input
    d1.TinhTien(dx, dy);

    // Display the new position of the point
    cout << "Point d1 after translation: ";
    d1.Xuat();

    return 0;
}
