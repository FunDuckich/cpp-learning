#include <iostream>

int main() {
    int n;
    std::cin >> n;

    long long total_sum = 0;

    int target_index = 1;

    for (int current_index = 1; current_index <= n; current_index++) {
        int current_num;
        std::cin >> current_num;

        if (current_index == target_index) {
            total_sum += current_num;

            target_index *= 2;
        }
    }

    std::cout << total_sum << std::endl;
}
