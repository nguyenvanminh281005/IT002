#include <bits/stdc++.h>
using namespace std;

class MaTran {
private:
    int m, n;
    vector<vector<int>> data;

public:
    MaTran(int rows = 0, int cols = 0) : m(rows), n(cols) {
        data.resize(m, vector<int>(n, 0));
    }

    friend istream& operator>>(istream &is, MaTran &mt) {
        cout << "Nhap ma tran " << mt.m << "x" << mt.n << ":\n";
        for (int i = 0; i < mt.m; ++i) {
            for (int j = 0; j < mt.n; ++j) {
                cout << "Nhap phan tu [" << i + 1 << "][" << j + 1 << "]: ";
                is >> mt.data[i][j];
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream &os, const MaTran &mt) {
        for (int i = 0; i < mt.m; ++i) {
            for (int j = 0; j < mt.n; ++j) {
                os << mt.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    MaTran operator+(const MaTran &other) const {
        if (m != other.m || n != other.n) {
            throw invalid_argument("Hai ma tran phai cung kich thuoc de thuc hien phep cong.");
        }
        MaTran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    MaTran operator-(const MaTran &other) const {
        if (m != other.m || n != other.n) {
            throw invalid_argument("Hai ma tran phai cung kich thuoc de thuc hien phep tru.");
        }
        MaTran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    MaTran operator*(const MaTran &other) const {
        if (n != other.m) {
            throw invalid_argument("So cot cua ma tran thu nhat phai bang so dong cua ma tran thu hai.");
        }
        MaTran result(m, other.n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < other.n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int m, n, p, q;

    cout << "Nhap so dong va cot cua ma tran thu nhat (m x n): ";
    cin >> m >> n;
    MaTran mt1(m, n);

    cout << "Nhap so dong va cot cua ma tran thu hai (p x q): ";
    cin >> p >> q;
    if (n != p) {
        cout << "So cot cua ma tran thu nhat phai bang so dong cua ma tran thu hai de thuc hien phep nhan." << endl;
        return -1;
    }
    MaTran mt2(p, q);

    cout << "\nNhap ma tran thu nhat:\n";
    cin >> mt1;
    cout << "Nhap ma tran thu hai:\n";
    cin >> mt2;

    cout << "\nMa tran thu nhat la:\n" << mt1;
    cout << "Ma tran thu hai la:\n" << mt2;

    try {
        MaTran sum = mt1 + mt2;
        cout << "\nTong cua hai ma tran:\n" << sum;
    } catch (const invalid_argument &e) {
        cout << "\nLoi phep cong: " << e.what() << endl;
    }

    try {
        MaTran diff = mt1 - mt2;
        cout << "\nHieu cua hai ma tran:\n" << diff;
    } catch (const invalid_argument &e) {
        cout << "\nLoi phep tru: " << e.what() << endl;
    }

    try {
        MaTran prod = mt1 * mt2;
        cout << "\nTich cua hai ma tran:\n" << prod;
    } catch (const invalid_argument &e) {
        cout << "\nLoi phep nhan: " << e.what() << endl;
    }

    return 0;
}
