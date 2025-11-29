#include <fstream>
#include <string>
#include <sstream>

int countWordOccurrences(const std::string &line, const std::string &targetWord) {
    std::stringstream ss(line);
    std::string word;
    int count = 0;

    while (ss >> word) {
        if (word == targetWord) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    std::string line;
    while (std::getline(inputFile, line)) {
        int occurrences = countWordOccurrences(line, "python");
        if (occurrences >= 2) {
            outputFile << line << std::endl;
        }
    }
}
