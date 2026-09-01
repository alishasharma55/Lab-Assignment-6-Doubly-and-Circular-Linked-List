#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

// Insert character at end
void insert(Node*& head, Node*& tail, char value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Check palindrome
bool isPalindrome(Node* head, Node* tail) {
    Node* left = head;
    Node* right = tail;

    while (left != nullptr && right != nullptr &&
           left != right && left->prev != right) {

        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
}

// Display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " <-> ";

        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";

    for (int i = 0; i < n; i++) {
        cin >> ch;
        insert(head, tail, ch);
    }

    cout << "Doubly Linked List: ";
    display(head);

    if (isPalindrome(head, tail))
        cout << "The linked list is a Palindrome.";
    else
        cout << "The linked list is not a Palindrome.";

    return 0;
}
