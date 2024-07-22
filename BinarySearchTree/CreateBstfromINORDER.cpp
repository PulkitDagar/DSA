//as we know the inorder of bst would be sorted
#include <iostream>
using namespace std;

Node* bstUsingInorder(int inorder[], int start, int end){
  //base case
  if(start>end){
    return NULL;
  }

  int mid = (start+end)/2;
  int element = inorder[mid];

  Node* root = new Node(element);

  root->left = bstUsingInorder(inorder,start,mid-1);
  root->right = bstUsingInorder(inorder,mid+1,end);

  return root;
}

int main() {
  int inorder[] = {1,2,3,4,5,6,7,8,9};
  int start = 0;
  int end = 8;
  Node* root = bstUsingInorder(inorder,start,end);
  levelOrderTraversal(root);
  return 0;
}