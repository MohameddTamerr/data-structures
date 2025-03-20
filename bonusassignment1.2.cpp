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

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void InsertSorted(int x) {
        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (head->data >= x) {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != head && current->next->data < x) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void PrintList() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void MakeNull() {
        if (head == nullptr) return;
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = nullptr;
    }
};

int main() {
    CircularLinkedList list;
    list.InsertSorted(5);
    list.InsertSorted(2);
    list.InsertSorted(8);
    list.InsertSorted(3);
    list.PrintList();
    list.MakeNull();
    return 0;
}