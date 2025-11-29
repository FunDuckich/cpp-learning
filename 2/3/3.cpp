#include <iostream>
#include <cmath>


float calculateY(const float x) {
    float abs_x = fabsf(x);

    if (abs_x <= 1.0f) {
        return x * x - 1.0f;
    }

    if (abs_x <= 2.0f) {
        return 2.0f * x - 1.0f;
    }

    return powf(x, 5.0f) - 1.0f;
}

float F(const float x) {
    return calculateY(x);
}

void F(const float x, float &y) {
    y = calculateY(x);
}

int main() {
    float x1 = 0.5f;
    float x2 = -2.0f;
    float x3 = 3.0f;

    std::cout << "--- Demonstrating function overloading ---" << std::endl;

    std::cout << "\nTesting with x = " << x1 << std::endl;
    const float result_v1_x1 = F(x1);
    std::cout << "returns float: F(0.5) = " << result_v1_x1 << std::endl;

    float result_v2_x1;
    F(x1, result_v2_x1);
    std::cout << "modifies by ref: F(0.5, y) => y = " << result_v2_x1 << std::endl;

    std::cout << "\nTesting with x = " << x2 << std::endl;
    const float result_v1_x2 = F(x2);
    std::cout << "returns float: F(-2.0) = " << result_v1_x2 << std::endl;

    float result_v2_x2;
    F(x2, result_v2_x2);
    std::cout << "modifies by ref: F(-2.0, y) => y = " << result_v2_x2 << std::endl;

    std::cout << "\nTesting with x = " << x3 << std::endl;
    const float result_v1_x3 = F(x3);
    std::cout << "returns float: F(3.0) = " << result_v1_x3 << std::endl;

    float result_v2_x3;
    F(x3, result_v2_x3);
    std::cout << "modifies by ref: F(3.0, y) => y = " << result_v2_x3 << std::endl;
}
