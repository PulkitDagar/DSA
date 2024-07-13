// 236. Lowest Common Ancestor of a Binary Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        //check for p and q
        if(root->val==p->val){
            return p;
        };
        if(root->val == q->val){
            return q;
        };

        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns==NULL && rightAns == NULL){
            return NULL;
        }
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else if(rightAns!=NULL && leftAns == NULL){
            return rightAns;
        }
        else{
            // (leftAns!=NULL && rightAns!=NULL)
            return root;
        }
    }
};