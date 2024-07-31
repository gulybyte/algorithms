#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class ResizableArray {
private:
    int* data;
    int size;
    int capacity;

    void ensureCapacity(int minCapacity) {
        if (minCapacity > capacity) {
            int newCapacity = capacity * 2;
            if (newCapacity < minCapacity) {
                newCapacity = minCapacity;
            }
            resize(newCapacity);
        }
    }

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void checkPositionIndex(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
    }

public:
    ResizableArray() : data(new int[10]), size(0), capacity(10) {}

    ~ResizableArray() {
        delete[] data;
    }

    void add(int element) {
        ensureCapacity(size + 1);
        data[size++] = element;
    }

    void add(int index, int element) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }
        ensureCapacity(size + 1);
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        size++;
    }

    int get(int index) const {
        checkPositionIndex(index);
        return data[index];
    }

    void set(int index, int element) {
        checkPositionIndex(index);
        data[index] = element;
    }

    int remove(int index) {
        checkPositionIndex(index);
        int removedValue = data[index];
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
        return removedValue;
    }

    int indexOf(int value) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    int getSize() const {
        return size;
    }

    vector<int> getAll() const {
        vector<int> elements(data, data + size);
        return elements;
    }
};

string assertEqualsVectorInt(vector<int> expected, vector<int> actual);
string assertEqualsInt(int expected, int actual);

int main() {
    ResizableArray arr;

    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(1, 10);
    arr.add(0, 20);

    vector<int> elements = arr.getAll();
    cout << "Elements: ";
    for (int elem : elements) {
        cout << elem << " ";
    }
    cout << endl;

    vector<int> expectedElements = {20, 1, 10, 2, 3};
    string status = assertEqualsVectorInt(expectedElements, elements);
    cout << "Comparison: " << status << endl;

    cout << "Size: " << arr.getSize() << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;

    arr.set(2, 30);
    cout << "Set index 2 to 30" << endl;
    elements = arr.getAll();
    for (int elem : elements) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Remove element at index 2: " << arr.remove(2) << endl;
    elements = arr.getAll();
    for (int elem : elements) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Index of element 2: " << arr.indexOf(2) << endl;
    cout << "Index of element 100 (not found): " << arr.indexOf(100) << endl;

    return 0;
}

string assertEqualsVectorInt(vector<int> expected, vector<int> actual) {
    if (expected == actual) {
        return "OK!";
    }
    return "NOT EQUALS!";
}

string assertEqualsInt(int expected, int actual) {
    if (expected == actual) {
        return "OK!";
    }
    return "NOT EQUALS!";
}
