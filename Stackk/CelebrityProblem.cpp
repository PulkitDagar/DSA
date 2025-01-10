// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Return the index of the celebrity, if there is no celebrity return -1.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        
        //push all elements in stack
        for(int i=0; i<n; i++){
            st.push(i);
            
        };
        //step 2 run discard method to find might be celebrity
        while(st.size()!= 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            //check if a knows b or not
            if(M[a][b]){
                //a is not celebrity b might be
                st.push(b);
            }
            else{
                //b is not celebrity a might be
                st.push(a);
            }
        };
        //check singe person is actually celebrity or not
        int mightBeCelebrity = st.top(); st.pop();
        
        //celebrity should not know anyone
        for(int i=0; i<n; i++){
            if(M[mightBeCelebrity][i] !=0){
                return -1;
            } 
        };
        
        //everyone must know celebrity
        for(int i=0; i<n; i++){
            if(M[i][mightBeCelebrity] ==0 && i!= mightBeCelebrity){
                return -1;
            }
        };
        return mightBeCelebrity;
    }
};