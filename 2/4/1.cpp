#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <memory>


template<typename T>
T **create_table(const int rows, const int cols) {
    T **table = new T *[rows];
    for (int i = 0; i < rows; i++) {
        table[i] = new T[cols];
    }
    return table;
}

template<typename T>
T **create_table(const int size) {
    return create_table<T>(size, size);
}

template<typename T>
void free_table(T **table, const int rows) {
    if (table == nullptr) return;
    for (int i = 0; i < rows; i++) {
        delete[] table[i];
    }
    delete[] table;
}

template<typename T>
void fill_zeros(T **table, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = 0;
        }
    }
}

template<typename T>
void fill_random(T **table, const int rows, const int cols) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = static_cast<T>(distrib(gen));
        }
    }
}

template<typename T>
void fill_from_keyboard(T **table, const int rows, const int cols) {
    std::cout << "enter " << rows * cols << " elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> table[i][j];
        }
    }
}

template<typename T>
void fill_from_file(T **table, const int rows, const int cols, const std::string &filename) {
    std::ifstream file(filename);
    int file_rows, file_cols;
    file >> file_rows >> file_cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> table[i][j];
        }
    }
}

template<typename T>
void print_to_console(T **table, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(8) << table[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
void print_to_file(T **table, const int rows, const int cols, const std::string &filename) {
    std::ofstream file(filename);
    file << rows << " " << cols << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file << table[i][j] << (j == cols - 1 ? "" : " ");
        }
        file << std::endl;
    }
}

template<typename T>
double average_bottom_right(T **table, const int rows, const int cols) {
    const int start_row = rows / 2;
    const int start_col = cols / 2;
    double sum = 0;
    int count = 0;
    for (int i = start_row; i < rows; i++) {
        for (int j = start_col; j < cols; j++) {
            sum += table[i][j];
            count++;
        }
    }
    return (count == 0) ? 0.0 : sum / count;
}


template<typename T>
using unique_table = std::unique_ptr<std::unique_ptr<T[]>[]>;

template<typename T>
unique_table<T> create_smart_table(int rows, int cols) {
    auto table = std::make_unique<std::unique_ptr<T[]>[]>(rows);
    for (int i = 0; i < rows; i++) {
        table[i] = std::make_unique<T[]>(cols);
    }
    return table;
}

template<typename T>
unique_table<T> create_smart_table(const int size) {
    return create_smart_table<T>(size, size);
}

template<typename T>
void fill_zeros(const unique_table<T> &table, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = 0;
        }
    }
}

template<typename T>
void fill_from_file(const unique_table<T> &table, const int rows, const int cols, const std::string &filename) {
    std::ifstream file(filename);
    int file_rows, file_cols;
    file >> file_rows >> file_cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> table[i][j];
        }
    }
}

template<typename T>
void print_to_console(const unique_table<T> &table, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(8) << table[i][j];
        }
        std::cout << std::endl;
    }
}

template<typename T>
double average_bottom_right(const unique_table<T> &table, const int rows, const int cols) {
    int start_row = rows / 2;
    int start_col = cols / 2;
    double sum = 0;
    int count = 0;
    for (int i = start_row; i < rows; i++) {
        for (int j = start_col; j < cols; j++) {
            sum += table[i][j];
            count++;
        }
    }
    return (count == 0) ? 0.0 : sum / count;
}


int main() {
    std::cout << "### i: raw pointers ###\n";

    const int rows = 3;
    const int cols = 4;
    int **int_table = create_table<int>(rows, cols);

    fill_from_file(int_table, rows, cols, "table_data.txt");

    std::cout << "table content:\n";
    print_to_console(int_table, rows, cols);

    const double avg_raw = average_bottom_right(int_table, rows, cols);
    std::cout << "average of bottom-right quadrant: " << avg_raw << "\n";

    std::cout << "freeing memory manually...\n";
    free_table(int_table, rows);

    std::cout << "\n\n### ii: smart pointers ###\n";

    const auto smart_int_table = create_smart_table<int>(rows, cols);

    fill_from_file(smart_int_table, rows, cols, "table_data.txt");

    std::cout << "smart table content:\n";
    print_to_console(smart_int_table, rows, cols);

    const double avg_smart = average_bottom_right(smart_int_table, rows, cols);
    std::cout << "average of bottom-right quadrant: " << avg_smart << "\n";

    std::cout << "cleanup is automatic! memory will be freed when 'smart_int_table' goes out of scope.\n";
}
