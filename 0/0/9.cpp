#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n % 3 == 0 && n % 10 == 3) {
        std::cout << 0 << std::endl;
    } else if (n % 3 == 0 || n % 10 == 3) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}
