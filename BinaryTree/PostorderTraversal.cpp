#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

// It returns root node of the created tree
Node* createTree(){
  cout << "Enter the value:" << endl;
  int data;
  cin >> data;

  if(data == -1){
    return NULL;
  }

  // Create a node, the recursion will handle the rest
  Node* root = new Node(data);

  // Left sub tree
  root->left = createTree();

  // Right sub tree
  root->right = createTree();

  return root;
}


void postOrderTraversal(Node* root){
  // Base case
  if(root == NULL){
    return;
  }
  // L R N

  // Recursive call for left subtree
  postOrderTraversal(root->left);
 
  // Recursive call for right subtree
  postOrderTraversal(root->right);
 
  cout<< root->data << endl;

};






int main() {
  Node* root = createTree();
  
  // Preorder traversal of the tree
  postOrderTraversal(root);
  
  return 0;
}