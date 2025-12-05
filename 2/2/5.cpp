#include <iostream>
#include <string>
#include <sstream>

void normalizeSpaces(std::string &line) {
    std::stringstream ss(line);
    std::string word;
    std::string result;

    while (ss >> word) {
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }
    line = result;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::string current_line;
        getline(std::cin, current_line);
        normalizeSpaces(current_line);
        std::cout << current_line << std::endl;
    }
}
