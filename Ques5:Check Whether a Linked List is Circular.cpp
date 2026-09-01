#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert node at end
void insert(Node*& head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Check whether linked list is circular
bool isCircular(Node* head) {
    if (head == nullptr)
        return false;

    Node* temp = head->next;

    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return temp == head;
}

int main() {
    Node* head = nullptr;
    int n, value, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }

    // Ask whether to make the list circular
    cout << "Make the linked list circular? (1 = Yes, 0 = No): ";
    cin >> choice;

    if (choice == 1) {
        Node* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = head;
    }

    if (isCircular(head))
        cout << "The linked list is a Circular Linked List.";
    else
        cout << "The linked list is not a Circular Linked List.";

    return 0;
}
