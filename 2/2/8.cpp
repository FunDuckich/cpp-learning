#include <iostream>
#include <vector>

std::vector<std::vector<int> > transpose(const std::vector<std::vector<int> > &matrix) {
    if (matrix.empty()) {
        return {};
    }

    const size_t n = matrix.size();
    const size_t m = matrix[0].size();

    std::vector<std::vector<int>> transposed_matrix(m, std::vector<int>(n));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }

    return transposed_matrix;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> original_matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> original_matrix[i][j];
        }
    }

    const std::vector<std::vector<int>> result_matrix = transpose(original_matrix);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << result_matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}
