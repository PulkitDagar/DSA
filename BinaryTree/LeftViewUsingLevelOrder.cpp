#include <iostream>
#include <queue>
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

Node* createTree() {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    root->left = createTree();
    root->right = createTree();

    return root;
}

void printLeftView(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* currentNode = q.front();
            q.pop();

            // Print the first node of each level
            if (i == 0) {
                cout << currentNode->data << " ";
            }

            if (currentNode->left) {
                q.push(currentNode->left);
            }

            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
    }
    cout << endl;
}

int main() {
    cout << "Enter tree data (use -1 for NULL nodes):" << endl;
    Node* root = createTree();
    cout << "Left View of the tree is:" << endl;
    printLeftView(root);
    return 0;
}







// void printLeftView(Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     bool firstNodeOfLevel = true;

//     while (!q.empty()) {
//         Node* front = q.front();
//         q.pop();

//         if (front == NULL) {
//             firstNodeOfLevel = true;  // Reset the flag for the new level
//             if (!q.empty()) {
//                 q.push(NULL);
//             }
//         } else {
//             if (firstNodeOfLevel) {
//                 // Print the first node of each level
//                 cout << front->data << " ";
//                 firstNodeOfLevel = false;
//             }

//             if (front->left != NULL) {
//                 q.push(front->left);
//             }
//             if (front->right != NULL) {
//                 q.push(front->right);
//             }
//         }
//     }
//     cout << endl;
// }