#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = 3.1415926535;

int main() {
    double x;

    std::cout << "ln|cos(x)| / ln(1 + x^2)" << std::endl;
    std::cout << "x = ";
    std::cin >> x;

    if (fabs(x) < 1e-9) {
        std::cout << "x can`t be 0" << std::endl;
        return 1;
    }

    double cos_x = cos(x);
    if (fabs(cos_x) < 1e-9) {
        std::cout << "cos(x) can`t be 0" << std::endl;
        return 1;
    }

    double numerator = log(fabs(cos_x));
    double denominator = log(1 + x * x);
    double result = numerator / denominator;

    std::cout << "Result: " << std::fixed << std::setprecision(6) << result << std::endl;
}
