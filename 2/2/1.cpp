#include <iostream>

bool isPrime(const int number) {
    if (number <= 1) {
        return false;
    }

    for (int d = 2; d * d <= number; d++) {
        if (number % d == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    bool is_first_output = true;

    for (int i = 100; i <= 999; ++i) {
        if (isPrime(i)) {
            if (!is_first_output) {
                std::cout << " ";
            }
            std::cout << i;
            is_first_output = false;
        }
    }

    std::cout << std::endl;
}
