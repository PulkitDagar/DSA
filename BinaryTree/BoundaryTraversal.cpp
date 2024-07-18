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
};

void printLeftBoundary(Node* root){
  //base case
  if(root==NULL){
    return;
  };

  if(root->left==NULL && root->right==NULL){
    return;
  };

  //process current node
  cout<<root->data<<" ";

  if(root->left){
    printLeftBoundary(root->left);
  }
  else{
    printLeftBoundary(root->right);
  }
};




void printLeafBoundary(Node* root){
  //base case
  if(root==NULL){
    return;
  };

  if(root->left==NULL && root->right==NULL){
    cout<<root->data<<" ";
  };

  printLeafBoundary(root->left);
  printLeafBoundary(root->right);
};

void printRightBoundary(Node* root){
  if(root==NULL){
    return;
  };
  if(root->left ==NULL && root->right == NULL){
    return;
  };

  if(root->right){
    printRightBoundary(root->right);
  }
  else{
    printRightBoundary(root->left);
  }
  cout<<root->data<<" ";
}

  
void boundaryTraversal(Node* root){
  if(root==NULL){
    return;
  };

  cout<<root->data<<endl;
  //step1:
  printLeftBoundary(root->left);

  //2;
  printLeafBoundary(root);

  // 3
  printRightBoundary(root->right);

}

int main(){
  Node* root = createTree();
  boundaryTraversal(root);

  return 0;
}