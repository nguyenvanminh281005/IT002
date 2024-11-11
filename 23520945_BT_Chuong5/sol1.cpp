#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
    double real;
    double fake;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), fake(i) {}

    double getReal() const { 
        return real; 
    }

    double getFake() const { 
        return fake; 
    }

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, fake + other.fake);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, fake - other.fake);
    }

    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - fake * other.fake,
                       real * other.fake + fake * other.real);
    }

    Complex operator/(const Complex &other) const {
        double denominator = other.real * other.real + other.fake * other.fake;
        if (denominator == 0) {
            throw runtime_error("Division by zero error: Denominator is zero.");
        }
        return Complex((real * other.real + fake * other.fake) / denominator,
                       (fake * other.real - real * other.fake) / denominator);
    }

    bool operator==(const Complex &other) const {
        return (real == other.real && fake == other.fake);
    }

    friend ostream &operator<<(ostream &os, const Complex &c) {
        if (c.fake >= 0)
            os << c.real << " + " << c.fake << "i";
        else
            os << c.real << " - " << -c.fake << "i";
        return os;
    }

    friend istream &operator>>(istream &is, Complex &c) {
        is >> c.real >> c.fake;
        return is;
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Nhap so phuc dau tien (phan thuc phan ao):" << endl;
    cin >> c1;
    cout << "Nhap so phuc thu hai (phan thuc phan ao):" << endl;
    cin >> c2;

    result = c1 + c2;
    cout << "Tong la: " << result << endl;

    result = c1 - c2;
    cout << "Hieu la: " << result << endl;

    result = c1 * c2;
    cout << "Tich la: " << result << endl;

    try {
        result = c1 / c2;
        cout << "Thuong la: " << result << endl;
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    if (c1 == c2)
        cout << "Hai so phuc bang nhau" << endl;
    else
        cout << "Hai so phuc khong bang nhau" << endl;

    return 0;
}
