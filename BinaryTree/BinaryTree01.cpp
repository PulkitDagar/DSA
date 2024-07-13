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
  };
};

//it returns root node of the created tree
Node* createTree(){
  cout<<"enter the value :"<<endl;
  int data;
  cin>>data;

  if(data==-1){
    return NULL;
  };

  //ek node create krdo baaki recursion sambhal lega
  Node* root = new Node(data);

  //left sub tree
  root->left = createTree();

  //right sub tree
  root->right = createTree();

  return root;
}

///second way to create Tree from level order traversal
// Node* createTreeLevelOrder() {
//     int data;
//     cout << "Enter the root value (-1 for NULL): ";
//     cin >> data;

//     if (data == -1) {
//         return NULL;
//     }

//     Node* root = new Node(data);
//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();

//         // Left child
//         cout << "Enter the left child of " << current->data << " (-1 for NULL): ";
//         cin >> data;
//         if (data != -1) {
//             current->left = new Node(data);
//             q.push(current->left);
//         }

//         // Right child
//         cout << "Enter the right child of " << current->data << " (-1 for NULL): ";
//         cin >> data;
//         if (data != -1) {
//             current->right = new Node(data);
//             q.push(current->right);
//         }
//     }

//     return root;
// }



int main() {
    ///creation of a binary tree
  Node* root = createTree();
  cout<<root->data<<endl;
  return 0;
}