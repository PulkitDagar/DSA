#include <iostream>
#include<stack>
using namespace std;

void solve(stack<int>&st, int pos, int &ans){
  //base case
  if(pos == 1){
    ans = st.top();
    return;
  };

  //1 case solve krdo
  int temp = st.top();
  st.pop();

  //recursion call
  solve(st,pos-1,ans);

  //backtracking
  st.push(temp);
}

int getMiddle(stack<int> &st){
  //first we check or odd and even
  int size = st.size();
  if(st.empty()){
    return -1;
  } else{
    //stack is not empty
    int pos = 0;
    if(size & 1){
      pos = size/2 + 1;
    } else{
      pos = size/2;
    };
    int ans = -1;
    solve(st,pos,ans);
    return ans;
  
  };
  

  
}


///quest 2 : find the middle element in a stack
int main(){
  stack<int>st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  int mid = getMiddle(st);

  cout<<"The middle of a stack is"<<mid<<endl;
 


  return 0;

}