#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool containsUppercase(const std::string& str) {
    for (const char c : str) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    std::string line;
    while (std::getline(inputFile, line)) {
        if (!containsUppercase(line)) {
            outputFile << line << std::endl;
        }
    }
}