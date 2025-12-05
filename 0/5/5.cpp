#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int first_neg_idx = -1;
    int last_neg_idx = -1;

    for (int i = 0; i < n; ++i) {
        if (numbers[i] < 0) {
            first_neg_idx = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (numbers[i] < 0) {
            last_neg_idx = i;
            break;
        }
    }

    double total_sum = 0.0;

    if (first_neg_idx != -1 && first_neg_idx < last_neg_idx) {
        for (int i = first_neg_idx + 1; i < last_neg_idx; ++i) {
            total_sum += numbers[i];
        }
    }

    std::cout << std::fixed << std::setprecision(3) << total_sum << std::endl;
}
