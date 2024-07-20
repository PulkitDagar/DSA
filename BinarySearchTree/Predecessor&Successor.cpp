#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void createTree(Node*& root) {
    int data;
    while (cin >> data && data != -1) {
        root = insertIntoBST(root, data);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

void findPredecessorAndSuccessor(Node* root, Node*& predecessor, Node*& successor, int key) {
    if (root == NULL) return;

    if (root->data == key) {
        // Find the maximum value in the left subtree (predecessor)
        if (root->left != NULL) {
            predecessor = findMax(root->left);
        }
        // Find the minimum value in the right subtree (successor)
        if (root->right != NULL) {
            successor = findMin(root->right);
        }
        return;
    }

    if (key < root->data) {
        successor = root;  // Update successor to current root
        findPredecessorAndSuccessor(root->left, predecessor, successor, key);
    } else {
        predecessor = root;  // Update predecessor to current root
        findPredecessorAndSuccessor(root->right, predecessor, successor, key);
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter the values for the BST (-1 to end input):" << endl;
    createTree(root);

    int key;
    cout << "Enter the key to find its in-order predecessor and successor: ";
    cin >> key;

    Node* predecessor = NULL;
    Node* successor = NULL;

    findPredecessorAndSuccessor(root, predecessor, successor, key);

    if (predecessor != NULL) {
        cout << "In-order predecessor of " << key << " is: " << predecessor->data << endl;
    } else {
        cout << "In-order predecessor of " << key << " does not exist." << endl;
    }

    if (successor != NULL) {
        cout << "In-order successor of " << key << " is: " << successor->data << endl;
    } else {
        cout << "In-order successor of " << key << " does not exist." << endl;
    }

    return 0;
}
