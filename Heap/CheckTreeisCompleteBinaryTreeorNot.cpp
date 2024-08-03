//check if the given complete binary tree is heap or not
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to check if the binary tree is complete using level-order traversal
bool isCompleteBinaryTree(Node* root) {
    if (root == nullptr)
        return true;
    
    queue<Node*> q;
    q.push(root);
    
    bool flag = false; // To check if a non-full node has been seen
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        if (current == nullptr) {
            flag = true; // All subsequent nodes must be NULL
        } else {
            if (flag)
                return false; // Found a non-NULL node after NULL node
            
            q.push(current->left);
            q.push(current->right);
        }
    }
    
    return true;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBinaryTree(root))
        cout << "The tree is a complete binary tree.\n";
    else
        cout << "The tree is not a complete binary tree.\n";

    return 0;
}
