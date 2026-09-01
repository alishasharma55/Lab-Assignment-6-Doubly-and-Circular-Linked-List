#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Insert at first
void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    cout << "Node inserted successfully.\n";
}

// Insert at last
void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Node inserted successfully.\n";
}

// Insert after a specific node
void insertAfter(int key, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == key) {
            Node* newNode = new Node();
            newNode->data = value;

            newNode->next = temp->next;
            temp->next = newNode;

            cout << "Node inserted after " << key << ".\n";
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Node " << key << " not found.\n";
}

// Insert before a specific node
void insertBefore(int key, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // If key is head
    if (head->data == key) {
        insertFirst(value);
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != key)
        temp = temp->next;

    if (temp->next == head) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted before " << key << ".\n";
}

// Delete a specific node
void deleteNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // If only one node exists
    if (head->data == key && head->next == head) {
        delete head;
        head = nullptr;

        cout << "Node deleted successfully.\n";
        return;
    }

    // If head is to be deleted
    if (head->data == key) {
        Node* last = head;

        while (last->next != head)
            last = last->next;

        Node* temp = head;
        head = head->next;
        last->next = head;

        delete temp;

        cout << "Node deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != head && temp->next->data != key)
        temp = temp->next;

    if (temp->next == head) {
        cout << "Node " << key << " not found.\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;

    delete del;

    cout << "Node deleted successfully.\n";
}

// Search
void search(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int position = 1;

    do {
        if (temp->data == key) {
            cout << "Node " << key
                 << " found at position " << position << ".\n";
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    cout << "Node " << key << " not found.\n";
}

// Display
void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";
}

int main() {
    int choice, value, key;

    do {
        cout << "\n===== CIRCULAR LINKED LIST =====\n";
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
