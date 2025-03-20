#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SortedSinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int counter;

    Node* InsertRecursive(Node* current, int x) {
        if (current == nullptr || current->data >= x) {
            Node* newNode = new Node(x);
            newNode->next = current;
            return newNode;
        }
        current->next = InsertRecursive(current->next, x);
        return current;
    }

public:
    SortedSinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }

    void InsertSorted(int x) {
        head = InsertRecursive(head, x);
        counter++;
    }

    void MakeNull() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }

    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SortedSinglyLinkedList list;
    list.InsertSorted(5);
    list.InsertSorted(2);
    list.InsertSorted(8);
    list.InsertSorted(3);
    list.PrintList();
    list.MakeNull();
    return 0;
}