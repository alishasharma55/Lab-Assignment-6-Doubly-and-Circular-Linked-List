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

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Display nodes and repeat head at end
void display(Node* head) {
    if (head == nullptr) {
        cout << "Circular Linked List is empty.";
        return;
    }

    Node* temp = head;

    // Display all nodes
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Display head again
    cout << head->data << endl;
}

int main() {
    Node* head = nullptr;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }

    cout << "Circular Linked List: ";
    display(head);

    return 0;
}
