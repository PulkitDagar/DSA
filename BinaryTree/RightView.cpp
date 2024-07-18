#include <iostream>
#include<queue>
#include<map>
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

Node* createTree(){
  int data;
  cin>>data;

  if(data==-1){
    return NULL;
  };

  //ek node create kro baaki recusion sambhal lega
  Node* root = new Node(data);

  //left hand side
  root->left = createTree();

  //right sub tree
  root->right = createTree();

  return root;

}

// Right view using recursion
void printRightTree(Node* root,vector<int> &ans, int level){
    //base case
    if(root==NULL){
        return;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    };

    //right
    printRightTree(root->right, ans, level+1);

    //left side
    printRightTree(root->left,ans,level+1);


};

int main() {
  Node* root = createTree();
  vector<int> ans;
    int level = 0;
    printRightTree(root,ans,level);

    for(auto i:ans){
        cout<<i<<" ";
    }
  
  return 0;
}