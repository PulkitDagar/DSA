#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// It returns root node of the created tree
Node *createTree()
{
    cout << "Enter the value:" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // Create a node, the recursion will handle the rest
    Node *root = new Node(data);

    // Left sub tree
    root->left = createTree();

    // Right sub tree
    root->right = createTree();

    return root;
}

// one way-------------------------------------
//  void levelOrderTraversal(Node* root){
//    queue<Node*>q;
//    q.push(root);

//   //traversal shuru krte hai
//   while(!q.empty()){
//     Node* front = q.front();
//     q.pop();

//     cout<<front->data<<" ";
//     if(front->left !=NULL){
//       q.push(front->left);
//     }
//     if(front->right !=NULL){
//       q.push(front->right);
//     }
//   }
// };

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // traversal shuru krte hai
    while (q.size() > 1)
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
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

int main()
{
    Node *root = createTree();

    // Preorder traversal of the tree
    levelOrderTraversal(root);

    return 0;
}
