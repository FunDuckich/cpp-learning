#include <iostream>

int main() {
    char c1, c2;
    std::cin >> c1 >> c2;
    std::string s;
    std::cin >> s;

    std::string result = "";
    for (const char current_char: s) {
        result += current_char;
        if (current_char == c2) {
            result += c1;
        }
    }

    std::cout << result << std::endl;
}
