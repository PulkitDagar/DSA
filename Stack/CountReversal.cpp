#include <iostream>
#include<stack>
using namespace std;
int countRev(string&s){
  //if odd size string impossible to make pairs
  if(s.size() & 1){
    return -1;
  }
  int ans =0;
  stack<char>st;
  for(int i=0; i<s.length(); i++){
    char ch = s[i];
    if( ch == '{'){
      st.push(ch);
    } else{
      if(!st.empty() && st.top() == '{'){
        st.pop();
      }
      else{
        st.push(ch);
      }
    }
  }

  //if stack is still not empty let check for reversals
  while(!st.empty()){
    char a = st.top();
    st.pop();
    char b = st.top();
    st.pop();

    if(a==b){
      ans = ans+1;
    }
    else{
      ans = ans+2;
    }
  }
  return ans;
}

// Count the reversals in a string }{{}}}}}
int main() {
  string s = "}{{}}{{{";

  int ans = countRev(s);
  cout<<"the ans will be"<<ans<<endl;
  return 0;
}