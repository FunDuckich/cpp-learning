#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int max1 = -101;
    int max2 = -102;


    for (int i = 0; i < n; i++) {
        int current_num;
        std::cin >> current_num;

        if (current_num > max1) {
            max2 = max1;
            max1 = current_num;
        } else if (current_num > max2 && current_num < max1) {
            max2 = current_num;
        }
    }

    std::cout << max2 << std::endl;
}
