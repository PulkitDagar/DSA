class Solution {
public:
    void solve(vector<string> &ans, int index, string output, string digits, vector<string> &mapping){
        //base case
        if(index>= digits.length()){
            ans.push_back(output);
            return;
        }