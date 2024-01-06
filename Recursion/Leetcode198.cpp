//House Robber Problem
class Solution {
public:

    int robHelper(vector<int>&nums,int i){
        //base case
        if(i>=nums.size()){
            return 0;
        }

        int robAmt1 = nums[i] + robHelper(nums,i+2);
        int robAmt2 = 0 + robHelper(nums,i+1);
        return max(robAmt1,robAmt2);
    }

    int rob(vector<int>& nums) {
        return robHelper(nums,0);
    }
};