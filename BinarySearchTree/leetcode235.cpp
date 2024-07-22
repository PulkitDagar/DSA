// Lowest Common Ancestor of a Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        };
        if(p->val < root->val && q->val <root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(p->val >root->val && q->val >root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(p->val <root->val && q->val >root->val){
            return root;
        }
        else{
            return root;
        }
    }
};