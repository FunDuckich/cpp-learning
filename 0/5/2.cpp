#include <iostream>

int main() {
    long long a, b;
    std::cin >> a >> b;

    long long prev = 0;
    long long curr = 1;

    bool first_printed = false;

    long long last_printed = -1;

    while (curr <= b) {
        if (curr >= a) {
            if (curr != last_printed) {
                if (first_printed) {
                    std::cout << " ";
                }
                std::cout << curr;
                last_printed = curr;
                first_printed = true;
            }
        }

        const long long next = prev + curr;
        if (next < curr) break;
        prev = curr;
        curr = next;
    }

    std::cout << std::endl;
}
