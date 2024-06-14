#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to check if a linked list is circular using Floyd's Cycle-Finding Algorithm
bool isCircular(Node* head) {
    if (head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;            // Moves one step
        fast = fast->next->next;      // Moves two steps

        // If slow and fast meet at some point then there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end, there is no cycle
    return false;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " - ";
        temp = temp->next;
    }
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    // Make the list circular for testing
    fourth->next = first;
    first->prev = fourth;

    // Check if the list is circular
    if (isCircular(first)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    return 0;
}
