#include <iostream>
#include <vector>

void shiftRowLeft(std::vector<int> &row) {
    if (row.size() <= 1) {
        return;
    }

    const int first_element = row[0];

    for (size_t i = 0; i < row.size() - 1; i++) {
        row[i] = row[i + 1];
    }

    row[row.size() - 1] = first_element;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        shiftRowLeft(matrix[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}
