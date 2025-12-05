#include <iostream>
#include <vector>

void reverseRows(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return;
    }

    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        std::swap(matrix[i], matrix[n - 1 - i]);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    reverseRows(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}