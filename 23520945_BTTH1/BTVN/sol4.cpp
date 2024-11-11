#include <iostream>
#include <vector>
using namespace std;

class matrix {
private:
    vector<vector<int>> mat; // 2D vector to store matrix
    int n; // size of the matrix (n x n)

public:
    // Constructor to initialize the matrix with size n x n
    matrix(int size) {
        n = size;
        mat.resize(n, vector<int>(n, 0)); // Initialize the matrix with zeroes
    }

    // Copy constructor
    matrix(const matrix& other) {
        n = other.n;
        mat = other.mat;
    }

    // Function to input the matrix
    void nhap() {
        cout << "Nhap ma tran " << n << "x" << n << ":" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to perform some calculation on the matrix
    // (For the sake of this example, I'll assume the calculation modifies the matrix somehow.
    // You can replace this logic with your own specific calculation)
    void cal() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] = (mat[i][j] + 1) % 10; // Example: increment each element and wrap around at 10
            }
        }
    }

    // Function to compare two matrices
    bool sosanh(const matrix& other) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != other.mat[i][j]) {
                    return false; // Matrices are not equal
                }
            }
        }
        return true; // Matrices are equal
    }

    // Function to display the matrix (optional, for debugging purposes)
    void xuat() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    matrix mat(n);
    mat.nhap();
    matrix matsave(mat); // Save the initial matrix state

    int count = 1;
    mat.cal(); // Perform the first calculation

    while (!mat.sosanh(matsave)) {
        mat.cal(); // Keep calculating until the matrix matches the saved one
        count++;
    }

    cout << count << endl; // Output the number of iterations
    return 0;
}
