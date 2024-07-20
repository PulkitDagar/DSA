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
};


bool findNodeInBST(Node* root, int target){
  //base case -> search krte krte end tk pouch gye
  if(root==NULL){
    return false;
  }

  if(root->data==target){
    return true;
  };

  //data hai vo bda hai root k data se
  if(target>root->data){
    return findNodeInBST(root->right,target);
  }
  if(target<root->data){
    return findNodeInBST(root->left,target);
  }
}

int main() {
    Node* root = NULL;
    cout << "Enter the values for the BST (-1 to end input):" << endl;
    createTree(root);

    int target = 15;
    bool ans = findNodeInBST(root,target);
    cout<<ans<<" ";

    // You can add additional code here to traverse the tree and check its structure.

    return 0;
}