#include <iostream>
#include <vector>

int findMinInSubmatrix(const std::vector<std::vector<int> > &matrix, const int k) {
    const size_t n = matrix.size();
    int min_value = matrix[k][k];

    for (int i = k; i < n; i++) {
        for (int j = k; j < n; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
        }
    }
    return min_value;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> b;
    b.reserve(n);
    for (int k = 0; k < n; k++) {
        b.push_back(findMinInSubmatrix(matrix, k));
    }

    for (int i = 0; i < b.size(); i++) {
        std::cout << b[i] << (i == b.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}
