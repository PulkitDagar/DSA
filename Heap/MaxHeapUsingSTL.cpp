#include <iostream>
#include <queue>
using namespace std;

int main() {
  //make a priority queue
  priority_queue<int> pq;   //aise create krne se max heap create hoti hai

  //now push element
  pq.push(2);
  pq.push(41);
  pq.push(5);
  pq.push(8);
  pq.push(12);

  //as we know max heap mee sbse uper maximum element hota hai
  cout<<"maximum element will be"<<pq.top()<<endl;

  //now we pop the element and jo element sbse uper hota hai whi pop hota hai
  pq.pop();

  cout<<pq.top();

  cout<<endl;


  //check size
  cout<<"size"<<pq.size()<<endl;

  if(pq.empty()){
    cout<<"max heap is empty"<<endl;
  }
  else{
    cout<<"max heap is not empty"<<endl;
  }


  return 0;
}