#include <iostream>
#include <vector>
using namespace std;

class Node{
  public:
  int data;
  vector<Node*> children;

  Node(int val){
    this->data = val;
  }
};

//it returns root node of the created tree
Node* createTree(){
  cout << "Enter the value (-1 to stop adding children): ";
  int data;
  cin >> data;

  if(data == -1){
    return NULL;
  }

  // Create the root node with the given data
  Node* root = new Node(data);

  // Read the number of children
  cout << "Enter the number of children for node " << data << ": ";
  int numChildren;
  cin >> numChildren;

  // Create each child and add to the children vector
  for(int i = 0; i < numChildren; i++){
    Node* child = createTree();
    if(child != NULL) {
      root->children.push_back(child);
    }
  }

  return root;
}

void printTree(Node* root, int depth = 0) {
  if(root == NULL) return;

  // Print the current node's data with indentation for tree structure
  for(int i = 0; i < depth; i++) cout << "--";
  cout << root->data << endl;

  // Recursively print each child
  for(Node* child : root->children) {
    printTree(child, depth + 1);
  }
}

int main() {
  Node* root = createTree();
  if(root != NULL) {
    printTree(root);
  }
  return 0;
}
