#include <bits/stdc++.h>
using namespace std;
struct cComplex {
    double real, img;
    cComplex() : real(0), img(0) {}
    cComplex(double r, double i) : real(r), img(i) {}
    void input() {
        cout << "Nhap phan thuc va phan ao: ";
        cin >> real >> img;
    }
    void print() const {
        cout << "(" << real << ", " << img << ")";
    }
    cComplex operator+(const cComplex &A) const {
        return cComplex(real + A.real, img + A.img);
    }
    cComplex operator-(const cComplex &A) const {
        return cComplex(real - A.real, img - A.img);
    }
    cComplex operator*(const cComplex &A) const {
        return cComplex(real * A.real - img * A.img, real * A.img + img * A.real);
    }
    cComplex operator/(const cComplex &A) const {
        double denominator = A.real * A.real + A.img * A.img;
        if (denominator == 0) {
            throw runtime_error("Division by zero.");
        }
        return cComplex(
            (real * A.real + img * A.img) / denominator,
            (img * A.real - real * A.img) / denominator
        );
    }
    void change_real(double x) { real = x; }
    void change_img(double x) { img = x; }
    double get_real() const { return real; }
    double get_img() const { return img; }
};
int main() {
    cComplex A, B, C;
    cout << "Nhap so phuc A:\n";
    A.input();
    cout << "Nhap so phuc B:\n";
    B.input();
    cout << "A: "; A.print(); cout << '\n';
    cout << "B: "; B.print(); cout << '\n';
    A.change_real(5);
    B.change_img(6);
    cout << "Imaginary part of A: " << A.get_img() << '\n';
    cout << "Real part of B: " << B.get_real() << '\n';
    C = A + B;
    cout << "A + B: "; C.print(); cout << '\n';
    C = A - B;
    cout << "A - B: "; C.print(); cout << '\n';
    C = A * B;
    cout << "A * B: "; C.print(); cout << '\n';
    try {
        C = A / B;
        cout << "A / B: "; C.print(); cout << '\n';
    } catch (const runtime_error &e) {
        cout << e.what() << '\n';
    }
    return 0;
}
