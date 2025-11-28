#include <iostream>
#include <iomanip>

int main() {
    double total_sum = 0.0;
    double current_number;
    int member_index = 1;

    while (std::cin >> current_number) {
        if (current_number < 0) {
            break;
        }

        if (member_index % 2 != 0) {
            total_sum -= current_number / member_index;
        } else {
            total_sum += current_number / member_index;
        }

        member_index++;
    }

    std::cout << std::fixed << std::setprecision(6) << total_sum << std::endl;
}
