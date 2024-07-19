class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        };

        //ek case solve krdo
        int leftpart = height(root->left);
        int rightpart = height(root->right);
        int ans = max(leftpart,rightpart) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        };

        //1case solve kro
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool ans = (diff<=1);

        //recursion call krdo
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(ans && leftAns && rightAns){
            return true;
        } else{
            return false;
        }
    }
};


//rule: leftHeight - rightHeight <=1;
// approach 2
// class Solution {
// public:
//     int checkHeight(TreeNode* root) {
//         if (root == NULL) {
//             return 0; // Height of an empty tree is 0
//         }

//         int leftHeight = checkHeight(root->left);
//         if (leftHeight == -1) return -1; // Left subtree is not balanced

//         int rightHeight = checkHeight(root->right);
//         if (rightHeight == -1) return -1; // Right subtree is not balanced

//         // Check if the current node is balanced
//         if (abs(leftHeight - rightHeight) > 1) {
//             return -1; // Not balanced
//         }

//         return max(leftHeight, rightHeight) + 1; // Return the height
//     }

//     bool isBalanced(TreeNode* root) {
//         return checkHeight(root) != -1; // If height is -1, the tree is not balanced
//     }
// };