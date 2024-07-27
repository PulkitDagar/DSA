#include <iostream>
using namespace std;


void convertIntoSortedDLL(Node* root, Node* &head){
  //base case
  if(root==NULL){
    return;
  }

  //convert right sub tree into linked list
  convertIntoSortedDLL(root->right, head);

  //attach root node
  root->right = head;

  //prev bhi lgao
  if(head!=NULL){
    head->left = root;
  }

  //update head
  head = root;

  //left sub tree rootnode
  convertIntoSortedDLL(root->left,head);
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
  convertIntoSortedDLL(root,head);
  printLinkedList(head);
  
  return 0;
}