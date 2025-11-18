#include <iostream>
#include <cmath>

int main() {
    long long o;
    std::cin >> o;

    double n_double = (-1.0 + sqrt(1.0 + 8.0 * o)) / 2.0;

    long long n = static_cast<long long>(n_double);

    std::cout << n << std::endl;
}
