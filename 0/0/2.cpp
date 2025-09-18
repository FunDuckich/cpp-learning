#include <iostream>

int main() {
    int n;
    int k;
    int m;
    int currentEntrance;
    int currentFloor;

    std::cin >> n;
    std::cin >> k;
    std::cin >> m;

    for (int entrance = 1; entrance < 1001; entrance++)
    {
        int maxRoomOnCurrentEntrance = entrance * k;

        if (n <= maxRoomOnCurrentEntrance) {
            currentEntrance = entrance;
            break;
        }
    }

    for (int floor = 1; floor < 1001; floor++) {
        int maxRoomOnCurrentFloor = floor * m;

        if (n <= maxRoomOnCurrentFloor) {
            currentFloor = floor;
            break;
        }
    }

    std::cout << currentEntrance << currentFloor;
}