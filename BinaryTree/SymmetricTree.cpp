//leetcode 101
//also known as mirror tree
class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p != NULL && q != NULL) {
            return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};