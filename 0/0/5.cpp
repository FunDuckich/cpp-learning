#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double ax, ay, bx, by;
    std::cin >> ax >> ay >> bx >> by;

    std::cout << std::fixed << std::setprecision(4) << sqrt((ax - bx)*(ax - bx)+ (ay - by)*(ay - by)) << std::endl;
}
