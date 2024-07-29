#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

    void checkPositionIndex(int index) const {
        if (index < 0 || index > size) {
            throw out_of_range("Indice error");
        }
    }

    void linkIsFirstOrLast(bool isFirst, int element) {
        Node* newNode = new Node(element);
        if (size == 0) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            if (isFirst) {
                head = newNode;
            } else {
                tail = newNode;
            }
        }
        size++;
    }

    void linkFirst(int element) {
        linkIsFirstOrLast(true, element);
    }

    void linkLast(int element) {
        linkIsFirstOrLast(false, element);
    }

    void linkBefore(int element, Node* succ) {
        Node* newNode = new Node(element);
        Node* pred = succ->prev;

        newNode->next = succ;
        newNode->prev = pred;
        pred->next = newNode;
        succ->prev = newNode;

        if (succ == head) {
            head = newNode;
        }
        if (succ == tail) {
            tail = newNode;
        }

        size++;
    }

    void unlink(Node* elementToDelete) {
        if(size == 1) {
            delete elementToDelete;
            head = tail = nullptr;
        } else {
            Node* prevElement = elementToDelete->prev;
            Node* nextElement = elementToDelete->next;
            prevElement->next = nextElement;
            nextElement->prev = prevElement;

            if (elementToDelete == head) {
                head = nextElement;
            }
            if (elementToDelete == tail) {
                tail = prevElement;
            }
            delete elementToDelete;
        }
        size--;
    }

    int indexOf(int value) const {
        Node* current = head;
        int index = 0;
        do {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        } while (current != head);

        return -1;
    }

    Node* node(int index) const {
        Node* current;
        if (index <= size / 2) {
            current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
        } else {
            current = tail;
            for (int i = size - 1; i > index; --i) {
                current = current->prev;
            }
        }
        return current;
    }

public:
    CircularDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int sizeList() const {
        return size;
    }

    void addFirst(int element) {
        linkFirst(element);
    }

    void addLast(int element) {
        linkLast(element);
    }

    void add(int index, int element) {
        checkPositionIndex(index);
        if (index == size) {
            addLast(element);
        } else if (index == 0) {
            addFirst(element);
        } else {
            linkBefore(element, node(index));
        }
    }

    void add(int element) {
        linkLast(element);
    }

    void deleteIndex(int index) {
        checkPositionIndex(index);
        unlink(node(index));
    }

    void deleteFirst() {
        checkPositionIndex(0);
        deleteIndex(0);
    }

    void deleteLast() {
        checkPositionIndex(0);
        deleteIndex(size - 1);
    }

    int get(int index) const {
        checkPositionIndex(index);
        return node(index)->data;
    }

    int getFirst() const {
        checkPositionIndex(0);
        return head->data;
    }

    int getLast() const {
        checkPositionIndex(size);
        return tail->data;
    }

    vector<int> getAll() const {
        vector<int> elements;
        if (size == 0) return elements;

        Node* current = head;
        do {
            elements.push_back(current->data);
            current = current->next;
        } while (current != head);

        return elements;
    }

    int search(int value) const {
        checkPositionIndex(0);
        int response = indexOf(value);
        if(response == -1) {
            throw out_of_range("Element Not Found");
        } else {
            return response;
        }
    }

    ~CircularDoublyLinkedList() {
        if (size == 0) return;

        Node* current = head;
        Node* next = nullptr;

        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != head);

        head = nullptr;
        tail = nullptr;
    }
};

string assertEqualsVectorInt(vector<int> expected, vector<int> actual);
string assertEqualsInt(int expected, int actual);

int main() {
    CircularDoublyLinkedList list;

    list.addFirst(10);
    list.addFirst(20);
    list.addFirst(30);

    list.addLast(40);
    list.addLast(50);

    list.add(2, 25);
    list.add(4, 35);

    list.add(60);

    vector<int> elements = list.getAll();
    cout << "Elements: ";
    for (int elem : elements) {
        cout << elem << " ";
    }

    vector<int> expectedElements = { 30, 20, 25, 10, 35, 40, 50, 60 };
    string status = assertEqualsVectorInt(expectedElements, elements);
    cout << "; " << status << endl;

    cout << "Size: " << list.sizeList();
    cout << " ; " << assertEqualsInt(8, list.sizeList()) << endl;

    cout << "First: " << list.getFirst() << " ; " << assertEqualsInt(30, list.getFirst()) << endl;
    cout << "Last: " << list.getLast() << " ; " << assertEqualsInt(60, list.getLast()) << endl;
    cout << "Index 4: " << list.get(4) << " ; " << assertEqualsInt(35, list.get(4)) << endl;


    list.deleteIndex(4);

    elements = list.getAll();
    cout << "Delete Index 4: ";
    for (int elem : elements) {
        cout << elem << " ";
    }
    expectedElements = { 30, 20, 25, 10, 40, 50, 60 };
    status = assertEqualsVectorInt(expectedElements, elements);
    cout << "; " << status << endl;


    list.deleteFirst();

    elements = list.getAll();
    cout << "Delete First: ";
    for (int elem : elements) {
        cout << elem << " ";
    }
    expectedElements = { 20, 25, 10, 40, 50, 60 };
    status = assertEqualsVectorInt(expectedElements, elements);
    cout << "; " << status << endl;


    list.deleteLast();

    elements = list.getAll();
    cout << "Delete Last: ";
    for (int elem : elements) {
        cout << elem << " ";
    }
    expectedElements = { 20, 25, 10, 40, 50 };
    status = assertEqualsVectorInt(expectedElements, elements);
    cout << "; " << status << endl;

    cout << "Search element 10: "<< list.search(10) << " ; " << assertEqualsInt(2, list.search(10)) << endl;

    //list.search(42); // NOT FOUND!

    return 0;
}

string assertEqualsVectorInt(vector<int> expected, vector<int> actual) {

    if(expected == actual) {
        return "OK!";
    }

    return "NOT EQUALS!";

}


string assertEqualsInt(int expected, int actual) {

    if(expected == actual) {
        return "OK!";
    }

    return "NOT EQUALS!";

}

