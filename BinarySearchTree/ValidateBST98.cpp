class Solution {
public:
    bool solve(TreeNode* root,int lowerBound,int upperBound){
        if(root==NULL){
            return true;
        }

        if(root->val >lowerBound && root->val<upperBound){
            bool leftAns = solve(root->left,lowerBound, root->val);
            bool rightAns = solve(root->right,root->val,upperBound);
            return leftAns && rightAns;
        } else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        int lowerBound = INT_MIN;
        int upperBound = INT_MAX;

        bool ans = solve(root,lowerBound,upperBound);
        return ans;
    }
};