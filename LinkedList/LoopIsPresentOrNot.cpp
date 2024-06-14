#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to detect a loop in a linked list using Floyd's Cycle-Finding Algorithm
bool hasLoop(Node* head) {
    if (head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Moves one step
        fast = fast->next->next;     // Moves two steps

        // If slow and fast meet at some point then there is a loop
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end, there is no loop
    return false;
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    // Create a loop for testing
    fourth->next = second;

    // Check if the list has a loop
    if (hasLoop(first)) {
        cout << "The linked list has a loop." << endl;
    } else {
        cout << "The linked list does not have a loop." << endl;
    }

    return 0;
}
