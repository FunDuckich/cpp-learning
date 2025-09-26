#include <iostream>

int main() {
    int a, x, b, y;

    std::cin >> a >> x >> b >> y;

    int total_salt_units = a * x + b * y;
    int total_volume = a + b;ф

    int final_concentration = total_salt_units / total_volume;

    std::cout << final_concentration << std::endl;
}