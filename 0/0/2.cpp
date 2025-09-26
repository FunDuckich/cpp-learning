#include <iostream>

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;

    int apartments_in_entrance = k * m;

    int entrance = (n - 1) / apartments_in_entrance + 1;
    int floor = ((n - 1) % apartments_in_entrance) / m + 1;

    std::cout << entrance << " " << floor << std::endl;
}
