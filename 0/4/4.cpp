#include <iostream>

bool isPrime(const int num) {
    if (num <= 1) {
        return false;
    }
    for (int d = 2; d * d <= num; d++) {
        if (num % d == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    int prime_down = n;
    while (!isPrime(prime_down)) {
        prime_down--;
    }

    int prime_up = n;
    while (!isPrime(prime_up)) {
        prime_up++;
    }

    const int dist_down = n - prime_down;
    const int dist_up = prime_up - n;

    if (dist_down <= dist_up) {
        std::cout << prime_down << std::endl;
    } else {
        std::cout << prime_up << std::endl;
    }
}
