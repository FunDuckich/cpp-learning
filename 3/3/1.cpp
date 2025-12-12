#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
};

void print_points(const std::string &message, const std::vector<Point> &points) {
    std::cout << message << "\n";
    for (const auto &p: points) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << "\n";
}

void task_a(std::vector<Point> &points) {
    const auto new_end = std::remove_if(points.begin(), points.end(), [](const Point &p) {
        return p.y < p.x;
    });
    points.erase(new_end, points.end());
}

long long task_b(const std::vector<Point> &points) {
    return std::count_if(points.begin(), points.end(), [](const Point &p) {
        return p.y == 0;
    });
}

void task_c(const std::vector<Point> &points) {
    const auto it = std::find_if(points.rbegin(), points.rend(), [](const Point &p) {
        return p.x > p.y;
    });

    if (it != points.rend()) {
        std::cout << "last point with x > y: (" << it->x << ", " << it->y << ")\n";
    } else {
        std::cout << "no point with x > y found\n";
    }
}

void task_g(std::vector<Point> &points) {
    std::stable_sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.y < b.y;
    });
}

int main() {
    const std::vector<Point> original_points = {
        {5, 2}, {3, 3}, {1, 4}, {7, 0}, {0, 0}, {-2, -5}, {-4, 0}, {8, 5}, {6, 5}
    };
    print_points("initial points:", original_points);

    std::cout << "\n--- running task a (delete y < x) ---";
    std::vector<Point> points_for_a = original_points;
    task_a(points_for_a);
    print_points("\npoints after deletion:", points_for_a);

    std::cout << "\n--- running task b (count y == 0) ---";
    const long long on_x_axis = task_b(original_points);
    std::cout << "\npoints on x-axis: " << on_x_axis << "\n";

    std::cout << "\n--- running task c (find last x > y) ---";
    task_c(original_points);

    std::cout << "\n--- running task g (stable sort by y) ---";
    std::vector<Point> points_for_g = original_points;
    task_g(points_for_g);
    print_points("\npoints after stable sort:", points_for_g);
}
