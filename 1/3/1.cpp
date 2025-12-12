#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cmath>

void explore_static_1d() {
    std::cout << "--- 1. 1d static array ---\n";
    const int size = 5;
    int arr[size];
    int arr_inited[size] = {1, 2, 3, 4, 5};
    std::cout << "uninitialized arr[0]: " << arr[0] << "\n";
    std::cout << "initialized arr_inited[0]: " << arr_inited[0] << "\n";

    std::ifstream file("data.txt");
    int n_from_file;
    file >> n_from_file;
    for (int i = 0; i < size; i++) {
        file >> arr[i];
    }
    file.close();
    std::cout << "array filled from file. arr[0]: " << arr[0] << "\n";

    std::cout << "\nelements and addresses:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "  value: " << arr[i] << ", address: " << &arr[i] << "\n";
    }

    std::cout << "\noperations:\n";
    std::cout << "  element at index 2: " << arr[2] << "\n";
    int min_abs_idx = 0;
    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) < std::abs(arr[min_abs_idx])) {
            min_abs_idx = i;
        }
    }
    std::cout << "  index of min absolute value: " << min_abs_idx << " (value: " << arr[min_abs_idx] << ")\n";
    std::swap(arr[0], arr[size - 1]);
    std::cout << "  after swapping first and last, new first is: " << arr[0] << "\n";

    std::cout << "cleanup: not required. stack memory is freed automatically.\n";
}

void explore_dynamic_1d() {
    std::cout << "\n--- 2. 1d dynamic array ---\n";
    int* arr = nullptr;
    int size;

    std::ifstream file("data.txt");
    file >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        file >> arr[i];
    }
    file.close();
    std::cout << "array of size " << size << " created and filled from file.\n";

    std::cout << "\nelements and addresses:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "  value: " << arr[i] << ", address: " << &arr[i] << "\n";
    }

    std::cout << "\noperations:\n";
    std::cout << "  element at index 2: " << arr[2] << "\n";
    int min_abs_idx = 0;
    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) < std::abs(arr[min_abs_idx])) {
            min_abs_idx = i;
        }
    }
    std::cout << "  index of min absolute value: " << min_abs_idx << " (value: " << arr[min_abs_idx] << ")\n";
    std::swap(arr[0], arr[size - 1]);
    std::cout << "  after swapping first and last, new first is: " << arr[0] << "\n";

    delete[] arr;
    std::cout << "cleanup: required! memory freed with delete[] arr.\n";
}

void explore_static_2d() {
    std::cout << "\n--- 3. 2d static array ---\n";
    const int rows = 3;
    const int cols = 4;
    int matrix[rows][cols];
    std::cout << "uninitialized matrix[0][0]: " << matrix[0][0] << "\n";

    std::ifstream file("data.txt");
    int temp_n, temp_val;
    file >> temp_n; for(int i=0; i < temp_n; i++) file >> temp_val;
    file >> temp_n >> temp_val;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();
    std::cout << "matrix filled from file. matrix[0][0]: " << matrix[0][0] << "\n";

    std::cout << "\naddresses of elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << &matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\noperations:\n";
    std::cout << "  element at [1][1]: " << matrix[1][1] << "\n";
    int min_r = 0, min_c = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(std::abs(matrix[i][j]) < std::abs(matrix[min_r][min_c])) {
                min_r = i; min_c = j;
            }
        }
    }
    std::cout << "  index of min absolute value: [" << min_r << "][" << min_c << "]\n";
    std::swap(matrix[0], matrix[rows - 1]);
    std::cout << "  after swapping first and last rows, new [0][0] is: " << matrix[0][0] << "\n";
    for (int i = 0; i < rows; i++) {
        std::swap(matrix[i][0], matrix[i][cols - 1]);
    }
    std::cout << "  after swapping first and last cols, new [0][0] is: " << matrix[0][0] << "\n";

    std::cout << "cleanup: not required. stack memory is freed automatically.\n";
}

void explore_dynamic_2d_jagged() {
    std::cout << "\n--- 4. 2d dynamic array (array of pointers) ---\n";
    int** matrix = nullptr;
    int rows, cols;

    std::ifstream file("data.txt");
    int temp; file >> temp; for(int i=0; i<temp; i++) file >> temp;
    file >> rows >> cols;

    matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();
    std::cout << "matrix " << rows << "x" << cols << " created and filled.\n";

    std::cout << "\naddresses of elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << &matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\noperations:\n";
    std::cout << "  element at [1][1]: " << matrix[1][1] << "\n";
    int min_r = 0, min_c = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(std::abs(matrix[i][j]) < std::abs(matrix[min_r][min_c])) {
                min_r = i; min_c = j;
            }
        }
    }
    std::cout << "  index of min absolute value: [" << min_r << "][" << min_c << "]\n";
    std::swap(matrix[0], matrix[rows - 1]);
    std::cout << "  after swapping first and last rows, new [0][0] is: " << matrix[0][0] << "\n";
    for (int i = 0; i < rows; i++) {
        std::swap(matrix[i][0], matrix[i][cols - 1]);
    }
    std::cout << "  after swapping first and last cols, new [0][0] is: " << matrix[0][0] << "\n";

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    std::cout << "cleanup: required! freed each row, then the array of pointers.\n";
}

void explore_dynamic_2d_flat() {
    std::cout << "\n--- 5. 2d dynamic array (single block) ---\n";
    int* matrix = nullptr;
    int rows, cols;

    std::ifstream file("data.txt");
    int temp; file >> temp; for(int i=0; i<temp; i++) file >> temp;
    file >> rows >> cols;

    matrix = new int[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i * cols + j];
        }
    }
    file.close();
    std::cout << "matrix " << rows << "x" << cols << " created as a single block.\n";

    std::cout << "\naddresses of elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << &matrix[i * cols + j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\noperations:\n";
    std::cout << "  element at [1][1]: " << matrix[1 * cols + 1] << "\n";
    int min_idx = 0;
    for(int i = 1; i < rows * cols; i++) {
        if(std::abs(matrix[i]) < std::abs(matrix[min_idx])) {
            min_idx = i;
        }
    }
    std::cout << "  index of min absolute value: " << min_idx << " (row " << min_idx / cols << ", col " << min_idx % cols << ")\n";

    for (int j = 0; j < cols; j++) {
        std::swap(matrix[0 * cols + j], matrix[(rows - 1) * cols + j]);
    }
    std::cout << "  after swapping first and last rows, new [0][0] is: " << matrix[0 * cols + 0] << "\n";
    for (int i = 0; i < rows; i++) {
        std::swap(matrix[i * cols + 0], matrix[i * cols + (cols - 1)]);
    }
    std::cout << "  after swapping first and last cols, new [0][0] is: " << matrix[0 * cols + 0] << "\n";

    delete[] matrix;
    std::cout << "cleanup: required! one simple delete[] for the whole block.\n";
}

int main() {
    explore_static_1d();
    explore_dynamic_1d();
    explore_static_2d();
    explore_dynamic_2d_jagged();
    explore_dynamic_2d_flat();
}