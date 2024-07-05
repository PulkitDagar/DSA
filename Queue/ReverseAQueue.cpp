#include <iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
  //create a stack
  stack<int> st;
  while(!q.empty()){
    int frontElement = q.front();
    q.pop();

    st.push(frontElement);
  };

  //one by one queue mai push krdo
  while(!st.empty()){
    int element = st.top();
    st.pop();

    q.push(element);
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

  reverseQueue(q);

  cout<<"printng queue"<<endl;

  while(!q.empty()){
    int element = q.front();
    q.pop();

    cout<<element<<" ";
  }


  return 0;
}