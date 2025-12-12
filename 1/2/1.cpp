#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

void explore_integers() {
    std::cout << "--- 1. integer types ---" << std::endl;
    std::cout << "size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "size of long long: " << sizeof(long long) << " bytes" << std::endl;

    std::cout << "\n[ranges]" << std::endl;
    std::cout << "int: " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "unsigned int: " << std::numeric_limits<unsigned int>::min() << " to " << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout << "\n[overflow]" << std::endl;
    unsigned int ui_max = std::numeric_limits<unsigned int>::max();
    int i_max = std::numeric_limits<int>::max();

    std::cout << "max unsigned int: " << ui_max << std::endl;
    ui_max++;
    std::cout << "max unsigned int + 1: " << ui_max << std::endl;

    std::cout << "max signed int: " << i_max << std::endl;
    i_max++;
    std::cout << "max signed int + 1: " << i_max << std::endl;
}

void explore_floats() {
    std::cout << "\n--- 2. floating-point types ---" << std::endl;
    std::cout << "size of float: " << sizeof(float) << ", precision (digits): ~" << std::numeric_limits<float>::digits10 << std::endl;
    std::cout << "size of double: " << sizeof(double) << ", precision (digits): ~" << std::numeric_limits<double>::digits10 << std::endl;

    std::cout << "\n[precision issues]" << std::endl;
    const double d1 = 0.1;
    const double d2 = 0.2;
    std::cout << std::setprecision(20);
    std::cout << "0.1 + 0.2 = " << d1 + d2 << " (not exactly 0.3!)" << std::endl;

    std::cout << "\n[boundary values]" << std::endl;
    const double zero = 0.0;
    std::cout << "1.0 / 0.0 = " << 1.0 / zero << std::endl;
    std::cout << "0.0 / 0.0 = " << 0.0 / zero << std::endl;
}

void explore_bool_and_char() {
    std::cout << "\n--- 3. bool and char types ---" << std::endl;
    std::cout << "size of bool: " << sizeof(bool) << " byte" << std::endl;
    std::cout << "true is " << true << ", false is " << false << std::endl;

    std::cout << "\nsize of char: " << sizeof(char) << " byte" << std::endl;
    const char c = 'a';
    std::cout << "char 'a' is stored as the integer value: " << static_cast<int>(c) << std::endl;
}

void explore_strings() {
    std::cout << "\n--- 4. std::string ---" << std::endl;
    std::string s_short = "hi";
    std::string s_long = "this is a very long string that will not fit in sso";

    std::cout << "sizeof(std::string) is always: " << sizeof(std::string) << " bytes" << std::endl;

    std::cout << "\nshort string \"" << s_short << "\":" << std::endl;
    std::cout << "  .size() = " << s_short.size() << ", .capacity() = " << s_short.capacity() << " (likely sso)" << std::endl;

    std::cout << "long string \"" << s_long.substr(0, 10) << "...\":" << std::endl;
    std::cout << "  .size() = " << s_long.size() << ", .capacity() = " << s_long.capacity() << " (heap allocated)" << std::endl;
}

int main() {
    explore_integers();
    explore_floats();
    explore_bool_and_char();
    explore_strings();
}