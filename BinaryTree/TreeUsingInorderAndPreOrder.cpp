#include <iostream>
#include<queue>
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

int findPosition(int arr[], int n, int element){
  for(int i=0; i<n; i++){
    if(arr[i]==element){
      return i;
    }
  }
  return -1;
}

//build tree from inordre and preorder
Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart,
  int inorderEnd ){

    //base case
    if(preIndex>=size|| inorderStart>inorderEnd){
      return NULL;
    }

    //step 1:
    int element = preorder[preIndex++];
    Node* root = new Node(element);

    int pos = findPosition(inorder,size,element);

    //position milgyi now solve root->left
    root->left = buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,inorderStart,pos-1);

    //step3: now solve for root->right
    root->right = buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,pos+1,inorderEnd);

    return root;
};

void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  // traversal shuru krte hai
  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();

    if (front == NULL)
        {
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            // valid node wala case
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
};

  

int main() {
  int inorder[] = {40,20,50,10,60,30,70};
  int preorder[] = {10,20,40,50,30,60,70};
  int size = 7;
  int preIndex = 0;
  int inorderStart = 0;
  int inorderEnd = size-1;

  Node* root = buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,inorderStart,inorderEnd);

  levelOrderTraversal(root);
  
  return 0;
}