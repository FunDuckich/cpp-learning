#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    double total_sum = 0.0;
    bool first_negative_found = false;
    bool second_negative_found = false;

    for (int i = 0; i < n; ++i) {
        double current_num;
        std::cin >> current_num;

        if (second_negative_found) {
            continue;
        }

        if (current_num < 0) {
            if (first_negative_found) {
                second_negative_found = true;
            } else {
                first_negative_found = true;
            }
        } else {
            if (first_negative_found) {
                total_sum += current_num;
            }
        }
    }

    if (second_negative_found) {
        std::cout << std::fixed << std::setprecision(3) << total_sum << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(3) << 0.0 << std::endl;
    }
}
