#include<iostream>
#include<stack>
using namespace std;

void insertInASortedArray(stack<int> &st, int element){
  //base case
  if(st.empty() || element>st.top()){
    st.push(element);
    return;
  };

  //1 case solve kro
  int temp = st.top();
  st.pop();

  //recursive call
  insertInASortedArray(st,element);


  //backtracking
  st.push(temp);
  
  
};

void print(stack<int>&st){
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  } cout<<endl;
}


int main(){
  //insert in a sorted array
  stack<int>st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  int element = 25;

  insertInASortedArray(st,element);
  print(st);

  return 0;
}