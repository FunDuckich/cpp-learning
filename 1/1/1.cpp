#include <iostream>
#include <cstdint>

int *p_num_global = nullptr;

void experiment1_pointers_init() {
    std::cout << "--- 1 ---" << std::endl;

    int *p_garbage;
    int *p_null = nullptr;

    std::cout << "address in uninitialized p_garbage: " << p_garbage << std::endl;
    std::cout << "address in p_null:                " << p_null << std::endl;
}

void experiment2_allocation() {
    std::cout << "\n--- 2 ---" << std::endl;

    p_num_global = new int(42);

    std::cout << "address in p_num_global: " << p_num_global << std::endl;
    std::cout << "value at that address (*p_num_global): " << *p_num_global << std::endl;
}

void experiment3_arithmetic() {
    std::cout << "\n--- 3 ---" << std::endl;

    std::cout << "p_num_global:      " << p_num_global << std::endl;
    std::cout << "p_num_global + 1: " << p_num_global + 1 << std::endl;

    const auto *bytes = reinterpret_cast<uint8_t *>(p_num_global);
    std::cout << "the first byte of our int has value: " << static_cast<int>(bytes[0]) << std::endl;
}

void experiment4_byte_change() {
    std::cout << "\n--- 4 ---" << std::endl;

    int number = 65;
    std::cout << "original number: " << number << std::endl;

    auto *bytes = reinterpret_cast<uint8_t *>(&number);
    std::cout << "changing its first byte to 66" << std::endl;
    bytes[0] = 66;

    std::cout << "changed number:  " << number << std::endl;
}

void experiment5_pointer_loss() {
    std::cout << "\n--- 5 ---" << std::endl;

    int *p1 = new int(111);
    int *p2 = new int(222);

    std::cout << "p2 holds address " << p2 << " with value " << *p2 << std::endl;
    std::cout << "now, let's 'lose' the pointer to 222" << std::endl;
    p2 = p1;
    std::cout << "we can no longer call 'delete' on the original address of 222" << std::endl;

    delete p1;
}

void experiment6_freeing_memory() {
    std::cout << "\n--- 6 ---" << std::endl;
    const int *p_del = new int(777);
    std::cout << "allocated memory at " << p_del << ", value is " << *p_del << std::endl;

    delete p_del;
    std::cout << "memory freed" << std::endl;
    std::cout << "it still holds the address " << p_del << ", but it's illegal to access it" << std::endl;
}

int main() {
    experiment1_pointers_init();
    experiment2_allocation();
    experiment3_arithmetic();
    experiment4_byte_change();
    experiment5_pointer_loss();
    experiment6_freeing_memory();

    delete p_num_global;
    p_num_global = nullptr;
}
