// leetcode543
class Solution {
public:
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        };

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight,rightHeight) + 1;

        return ans;
    };
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = maxDepth(root->left) + maxDepth(root->right);
        int ans = max(option1, max(option2,option3));
        return ans;
    }
};