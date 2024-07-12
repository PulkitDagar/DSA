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



int main() {
    ///creation of a binary tree
  Node* root = createTree();
  cout<<root->data<<endl;
  return 0;
}