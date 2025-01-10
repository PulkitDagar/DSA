#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// Function to remove duplicates without extra space
void removeDuplicatesWithoutExtraSpace(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return; // No duplicates possible
    }

    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* runner = curr;
        while (runner->next != nullptr) {
            if (runner->next->val == curr->val) {
                // Duplicate found, remove it
                ListNode* temp = runner->next;
                runner->next = runner->next->next;
                delete temp; // Free memory
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 2 -> 4 -> 3 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List:" << endl;
    printList(head);

    removeDuplicatesWithoutExtraSpace(head);

    cout << "List After Removing Duplicates:" << endl;
    printList(head);

    return 0;
}
