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

void printTopView(Node* root){
  //handle edge case
  if(root==NULL){
    return;
  };

  //create a map for storing horizontal dist ->and top->data
  map<int,int> topNode;

  //level order traversal
  //we will store a pair consisting of node and horizontal distance
  queue<pair<Node*,int>>q;

  q.push(make_pair(root,0));

  while(!q.empty()){
    pair<Node*,int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;

    //jo bhi horizontal distance aaya hai check if answer for that horizontal dis exists or not
    if(topNode.find(hd)==topNode.end()){
      //create entry
      topNode[hd] = frontNode->data;
    }
    if(frontNode->left){
      //ager left exist krta hai
      q.push(make_pair(frontNode->left,hd-1));
    };

    if(frontNode->right){
      //ager right exists karta hai
      q.push(make_pair(frontNode->right,hd+1));
    }
  };

  //ab hamara answer store hua hoga map mai
  cout<<"Printing the answer"<<endl;
  for(auto i:topNode){
    cout<<i.first<<" ->" << i.second<<endl;
  }

}

int main() {
  Node* root = createTree();
  printTopView(root);
  return 0;
}