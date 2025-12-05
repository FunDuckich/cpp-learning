#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point {
    int x, y;
};

long long distSq(const Point &p1, const Point &p2) {
    const long long dx = p1.x - p2.x;
    const long long dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

long long getSquareSideSq(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
    std::vector<long long> distances;
    distances.push_back(distSq(p1, p2));
    distances.push_back(distSq(p1, p3));
    distances.push_back(distSq(p1, p4));
    distances.push_back(distSq(p2, p3));
    distances.push_back(distSq(p2, p4));
    distances.push_back(distSq(p3, p4));

    std::sort(distances.begin(), distances.end());

    if (distances[0] > 0 &&
        distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] &&
        distances[4] == distances[5] &&
        distances[4] == 2 * distances[0]) {
        return distances[0];
    }

    return 0;
}

int main() {
    int n;
    std::cin >> n;

    if (n < 4) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    long long max_sq_side = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long current_sq_side = getSquareSideSq(points[i], points[j], points[k], points[l]);
                    if (current_sq_side > max_sq_side) {
                        max_sq_side = current_sq_side;
                    }
                }
            }
        }
    }

    if (max_sq_side == 0) {
        std::cout << 0 << std::endl;
    } else {
        const double side = sqrt(static_cast<double>(max_sq_side));
        const double perimeter = 4.0 * side;
        std::cout << std::fixed << std::setprecision(10) << perimeter << std::endl;
    }
}
