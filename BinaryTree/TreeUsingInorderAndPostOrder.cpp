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
Node* buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart,
  int inorderEnd ){

    //base case
    if(postIndex<0 || inorderStart>inorderEnd){
      return NULL;
    }

    //step 1:
    int element = postorder[postIndex];
    postIndex--;
    Node* root = new Node(element);

    int pos = findPosition(inorder,size,element);

    //position milgyi now solve root->right
    root->right = buildTreeFromPostOrderInOrder(inorder,postorder,size,postIndex,pos+1,inorderEnd);

    //step3: now solve for root->left
    root->left = buildTreeFromPostOrderInOrder(inorder,postorder,size,postIndex,inorderStart,pos-1);

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
  int inorder[] = {40,20,10,50,30,60};
  int postorder[] = {40,20,50,60,30,10};
  int size = 6;
  int postIndex = size-1;
  int inorderStart = 0;
  int inorderEnd = size-1;

  Node* root = buildTreeFromPostOrderInOrder(inorder,postorder,size,postIndex,inorderStart,inorderEnd);

  levelOrderTraversal(root);
  
  return 0;
}