#include <iostream>
#include <string>

void removeTextBetweenCommas(std::string &line) {
    std::string result = "";
    bool is_copying = true;

    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        if (c == ',') {
            is_copying = !is_copying;
        } else {
            if (is_copying) {
                result += c;
            }
        }
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
        removeTextBetweenCommas(current_line);
        std::cout << current_line << std::endl;
    }
}
