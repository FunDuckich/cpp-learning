#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    double final_answer = 0.0;
    double running_sum = 0.0;
    bool first_negative_found = false;
    int negative_count = 0;

    for (int i = 0; i < n; i++) {
        double current_num;
        std::cin >> current_num;

        if (!first_negative_found) {
            if (current_num < 0) {
                first_negative_found = true;
                negative_count++;
            }
        } else {
            if (current_num < 0) {
                final_answer = running_sum;
                negative_count++;
            }
            running_sum += current_num;
        }
    }

    if (negative_count < 2) {
        std::cout << std::fixed << std::setprecision(3) << 0.0 << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(3) << final_answer << std::endl;
    }
}
