#include <iostream>

int main() {
    int number;
    std::cout << "10) is the sum of the digits of a two-digit number odd?" << std::endl;
    std::cout << "enter a two-digit integer: ";
    std::cin >> number;

    if (number < 10 || number > 99) {
        std::cout << "the entered number is not a two-digit number!" << std::endl;
        return 1;
    }

    int first_digit = number / 10;
    int second_digit = number % 10;
    int sum_of_digits = first_digit + second_digit;

    std::cout << ((sum_of_digits % 2) != 0 ? "yes" : "no") << std::endl;
}