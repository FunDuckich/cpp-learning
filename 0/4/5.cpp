#include <iostream>

int main() {
    std::string s;
    getline(std::cin, s);

    int digit_count = 0;
    for (const char c: s) {
        if (isdigit(c)) {
            digit_count++;
        }
    }

    std::cout << digit_count << std::endl;
}
