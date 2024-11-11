#include <iostream>
#include <vector>
using namespace std;

// Struct to represent a rectangle with top-left corner (x, y) and dimensions (w, h)
struct rectangle {
    int x, y, w, h;
    rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
};

// Function to find rectangles of ones in the matrix
vector<rectangle> solve(vector<vector<int>>& matrix, int m, int n) { // Remove 'const' here
    vector<rectangle> rectangles;
    
    // A simple example: Find rectangles of continuous 1's in the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) { // Start of a rectangle
                int width = 0, height = 0;

                // Calculate width of the rectangle
                while (j + width < n && matrix[i][j + width] == 1) {
                    ++width;
                }

                // Calculate height of the rectangle
                while (i + height < m) {
                    bool full_row = true;
                    for (int k = 0; k < width; ++k) {
                        if (matrix[i + height][j + k] != 1) {
                            full_row = false;
                            break;
                        }
                    }
                    if (!full_row) break;
                    ++height;
                }

                // Mark the found rectangle area as visited (set to 0)
                for (int r = i; r < i + height; ++r) {
                    for (int c = j; c < j + width; ++c) {
                        matrix[r][c] = 0;
                    }
                }

                // Store the rectangle with top-left corner (i, j), width, and height
                rectangles.push_back(rectangle(i, j, width, height));
            }
        }
    }

    return rectangles;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Input the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    // Solve and find all rectangles
    vector<rectangle> rectangles = solve(matrix, m, n);

    // Output the rectangles found
    for (auto rect : rectangles) {
        cout << "[" << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << "]\n";
    }

    return 0;
}
