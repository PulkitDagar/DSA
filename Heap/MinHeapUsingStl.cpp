#include <iostream>
#include<queue>
using namespace std;

int main() {
  //how to create min heap
  priority_queue<int,vector<int>, greater<int> > pq;

  pq.push(2);
  pq.push(4);
  pq.push(5);
  pq.push(8);
  pq.push(12);

  cout<<"top element of min heap is "<<pq.top()<<endl;
  pq.pop();
  
  cout<<"size will be "<<pq.size();
  cout<<endl;

  if(pq.empty()){
    cout<<"min heap is empty"<<endl;
  }
  else{
    cout<<"min heap is not empty"<<endl;
  }

}