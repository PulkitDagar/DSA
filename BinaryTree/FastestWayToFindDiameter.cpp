// leetcode543
class Solution {
public:
    int D = 0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        };

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        //diameter
        int currD = leftHeight + rightHeight;
        D = max(D,currD);
        return max(leftHeight,rightHeight) + 1;

        
    };
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return D;
    }
};