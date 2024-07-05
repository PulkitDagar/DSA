#include <iostream>
#include<stack>
#include<queue>
using namespace std;


void reverseFirstK(queue<int>& q, int k){
  //push first k elements into stack
  stack<int>st;
  int n = q.size();
  for(int i=0; i<k; i++){
    int temp = q.front();
    q.pop();

    st.push(temp);
  }
  
  //push all k elements int queue
  while(!st.empty()){
    int temp = st.top();
    st.pop();
    q.push(temp); 
  }

  for(int i=0; i<(n-k); i++){
    int temp = q.front();
    q.pop();
    q.push(temp);
  }
}


int main() {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);

  // reverseQueue(q);
  reverseFirstK(q,4);

  cout<<"printng queue"<<endl;

  while(!q.empty()){
    int element = q.front();
    q.pop();

    cout<<element<<" ";
  }


  return 0;
}