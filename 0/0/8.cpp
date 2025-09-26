#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) {
        double p = (a + b + c) / 2.0;
        double s = std::sqrt(p * (p - a) * (p - b) * (p - c));

        std::cout << std::fixed << std::setprecision(6) << s << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}
