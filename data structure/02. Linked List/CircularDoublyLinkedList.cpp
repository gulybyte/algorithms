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
            throw out_of_range("Índice fora dos limites");
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

    Node* node(int index) const {
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
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

    int get(int index) const {
        checkPositionIndex(index);
        return node(index)->data;
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

