// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            int ch = s[i];
            //empty check
            if(st.empty()){
                st.push(ch);
            }
            else if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};