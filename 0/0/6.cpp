#include <iostream>

int main() {
    int num;
    std::cin >> num;

    int firstDigit = num / 100;
    int secondDigit = (num / 10) % 10;
    int thirdDigit = num % 10;

    if (firstDigit == secondDigit || firstDigit == thirdDigit || secondDigit == thirdDigit) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
