#include <iostream>
#include <sstream>

std::string normalizeSpaces(const std::string &input_str) {
    std::stringstream ss(input_str);
    std::string result;
    std::string word;

    while (ss >> word) {
        if (!result.empty()) {
            result += ' ';
        }
        result += word;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::string line;
        getline(std::cin, line);
        std::cout << normalizeSpaces(line) << std::endl;
    }
}
