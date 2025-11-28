#include <iostream>

bool isPowerOfFive(int num) {
    if (num < 1) {
        return false;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int current_number;
        std::cin >> current_number;
        if (isPowerOfFive(current_number)) {
            count++;
        }
    }

    std::cout << count << std::endl;
}
