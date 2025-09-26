#include <iostream>
#include <cmath>

int main() {
    double m;
    std::cin >> m;

    double n_double = (1.0 + std::sqrt(1.0 + 8.0 * m)) / 2.0;
    int n = static_cast<int>(n_double);

    std::cout << n << std::endl;
}