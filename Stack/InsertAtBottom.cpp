#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st, int element){
  //base case
  if(st.empty()){
    st.push(element);
    return;
  }

  //1 case mai solve krdunga
  int temp = st.top();
  st.pop();

  //bbaki recursion
  insertAtBottom(st,element);

  //backtrack
  st.push(temp);
}

int main() {
  stack<int>st;
  st.push(10);
  st.push(20);
  st.push(30);

  int element = 400;

  insertAtBottom(st,element);

  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }cout<<endl;
  return 0;
}