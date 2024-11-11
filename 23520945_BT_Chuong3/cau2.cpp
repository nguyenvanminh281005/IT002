#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Circle {
private:
    double radius;
    double x, y;
    double area;
    double circum;

public:
    Circle(double x_, double y_, double r)
        : x(x_), y(y_), radius(r)
    {
        area = M_PI * radius * radius;
        circum = 2 * M_PI * radius;
    }

    double getArea() const
    {
        return area;
    }

    double getCircumference() const
    {
        return circum;
    }

    void displayInformation() const
    {
        cout << fixed << setprecision(2);
        cout << "Chu vi: " << circum << '\n';
        cout << "Diện tích: " << area << '\n';
    }
};

int main()
{
    double x, y, r;
    cout << "Nhập tọa độ của đường tròn (x,y): ";
    cin >> x >> y;
    cout << "Nhập bán kính (r): ";
    cin >> r;

    Circle cir(x, y, r);
    cir.displayInformation();
    
    return 0;
}
