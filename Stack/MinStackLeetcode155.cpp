class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            //means I am inserting first element
            pair<int,int>p; 
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else{
            //not empty
            pair<int,int>p;
            p.first = val;
            int puranaMin = st.back().second;
            p.second = min(puranaMin, val);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.first;
    }
    
    int getMin() {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.second;
    }
};
