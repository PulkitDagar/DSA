class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        deque<int>dq;

        //processing first window
        for(int i=0; i<k; i++){
            int element = nums[i];
            //jitne bhi queue k ander chhote element hai unhe delete krdo
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            //now we push element
            dq.push_back(i);
        }
        //process remaining windows
        for(int i=k; i<nums.size(); i++){
            //ans store
            ans.push_back(nums[dq.front()]);

            //removal->out of range
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            //chhote element pop krdo
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            //addition
            dq.push_back(i);
        }

        //last window ka answer store krege
        ans.push_back(nums[dq.front()]);

        return ans;



            


    }
};