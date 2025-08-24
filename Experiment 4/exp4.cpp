#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtBegin(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBegin() {
        if (!head) return;
        DNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    CNode* tail;
public:
    CircularLinkedList() { tail = nullptr; }

    void insertAtBegin(int val) {
        CNode* newNode = new CNode(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void deleteAtBegin() {
        if (!tail) return;
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
            return;
        }
        CNode* temp = tail->next;
        tail->next = temp->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!tail) return;
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
            return;
        }
        CNode* temp = tail->next;
        while (temp->next != tail) temp = temp->next;
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    void display() {
        if (!tail) return;
        CNode* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

int main() {
    cout << "Doubly Linked List:" << endl;
    DoublyLinkedList dll;
    dll.insertAtBegin(10);
    dll.insertAtEnd(20);
    dll.insertAtBegin(5);
    dll.display();
    dll.deleteAtBegin();
    dll.display();
    dll.deleteAtEnd();
    dll.display();

    cout << "\nCircular Linked List:" << endl;
    CircularLinkedList cll;
    cll.insertAtBegin(10);
    cll.insertAtEnd(20);
    cll.insertAtBegin(5);
    cll.display();
    cll.deleteAtBegin();
    cll.display();
    cll.deleteAtEnd();
    cll.display();

    return 0;
}
