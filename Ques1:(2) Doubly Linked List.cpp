#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Insert at first
void insertFirst(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;

    cout << "Node inserted successfully.\n";
}

// Insert at last
void insertLast(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Node inserted successfully.\n";
}

// Insert after a specific node
void insertAfter(int key, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;

    cout << "Node inserted after " << key << ".\n";
}

// Insert before a specific node
void insertBefore(int key, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    cout << "Node inserted before " << key << ".\n";
}

// Delete a specific node
void deleteNode(int key) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    // If node is head
    if (temp == head)
        head = temp->next;

    // Connect previous node
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    // Connect next node
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Node " << key << " deleted successfully.\n";
}

// Search
void search(int key) {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node " << key
                 << " found at position " << position << ".\n";
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Node " << key << " not found.\n";
}

// Display
void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Doubly Linked List: ";

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " <-> ";

        temp = temp->next;
    }

    cout << " -> NULL\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After Specific Node\n";
        cout << "4. Insert Before Specific Node\n";
        cout << "5. Delete Specific Node\n";
        cout << "6. Search Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertFirst(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertLast(value);
                break;

            case 3:
                cout << "Enter node after which to insert: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(key, value);
                break;

            case 4:
                cout << "Enter node before which to insert: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBefore(key, value);
                break;

            case 5:
                cout << "Enter node to delete: ";
                cin >> key;
                deleteNode(key);
                break;

            case 6:
                cout << "Enter node to search: ";
                cin >> key;
                search(key);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
