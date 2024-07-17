#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size) : size(size) {
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        } else {
            std::cerr << "Index out of bounds" << std::endl;
        }
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            std::cerr << "Index out of bounds" << std::endl;
            return -1; // Valor de erro
        }
    }

    int getSize() {
        return size;
    }
};

int main() {
    DynamicArray arr(10);

    for (int i = 0; i < arr.getSize(); ++i) {
        arr.set(i, i * 2);
    }

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << "Value at index " << i << ": " << arr.get(i) << std::endl;
    }

    return 0;
}
