#include <iostream>

int main() {
    int toX, toY, inpX, inpY, inpZ;
    std::cin >> toX >> toY >> inpX >> inpY >> inpZ;

    if ((inpX <= toX && inpY <= toY) || (inpX <= toY && inpY <= toX) ||
        (inpX <= toX && inpZ <= toY) || (inpX <= toY && inpZ <= toX) ||
        (inpY <= toX && inpZ <= toY) || (inpY <= toY && inpZ <= toX)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
