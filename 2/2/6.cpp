#include <iostream>
#include <vector>

int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void findNumbers(const int k, const int n, std::vector<int> &result_array) {
    result_array.clear();

    for (int i = 1; i < n; i++) {
        if (sumOfDigits(i) == k) {
            result_array.push_back(i);
        }
    }
}

int main() {
    int num_columns;
    std::cin >> num_columns;

    std::vector<int> n_values(num_columns);
    std::vector<int> k_values(num_columns);

    for (int i = 0; i < num_columns; i++) {
        std::cin >> n_values[i];
    }
    for (int i = 0; i < num_columns; i++) {
        std::cin >> k_values[i];
    }

    std::vector<int> found_numbers;
    for (int i = 0; i < num_columns; i++) {
        int current_n = n_values[i];
        int current_k = k_values[i];

        findNumbers(current_k, current_n, found_numbers);

        std::cout << found_numbers.size() << std::endl;

        for (int j = 0; j < found_numbers.size(); j++) {
            std::cout << found_numbers[j] << (j == found_numbers.size() - 1 ? "" : " ");
        }

        if (!found_numbers.empty() || i < num_columns - 1) {
            std::cout << std::endl;
        }
    }
}
