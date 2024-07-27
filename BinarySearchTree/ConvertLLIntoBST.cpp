#include <iostream>
using namespace std;


Node* sortedLLIntoBST(Node* &head, int n){
  //base case
  if(n<=0 || head==NULL){
    return;
  };

  Node* leftSubtree = sortedLLIntoBST(head, n-1-n/2);

  //mid pe point kr rha hai head
  Node* root = head;
  root->left = leftSubtree;

  head = head->right;
  //right part solve karna hai
  root->right = sortedLLIntoBST(head,n/2);
  return root;
};

void printLinkedList(Node* &head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->right;
  }
}
int main() {

  Node* head = NULL;
  Node* root1 = NULL;
  root1 = sortedLLIntoBST(head,9);
  levelOrderTraversal(root1);
  
  
  return 0;
}