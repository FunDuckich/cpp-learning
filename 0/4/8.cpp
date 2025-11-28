#include <iostream>
#include <string>

int main() {
    std::string s;
    getline(std::cin, s);

    char c1, c2;
    std::cin >> c1 >> c2;

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        char current_char = *it;
        if (current_char == c1 || current_char == c2) {
            std::cout << current_char << std::endl;
            break;
        }
    }
}
