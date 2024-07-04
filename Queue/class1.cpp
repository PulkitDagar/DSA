#include <iostream>
#include<queue>
using namespace std;

int main() {
  //creation in queue
  queue<int>q;

  // insertion
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);

  cout<<"the first element will be"<<q.front()<<endl;
  cout<<"the last element will be"<<q.back()<<endl;
 

  //size
  cout<<"the size of queue is "<<q.size()<<" ";

  cout<<endl;

  //empty
  if(q.empty() == true){
    cout<<"queue is empty"<<endl;
  } else{
    cout<<"queue is not empty"<<endl;
  }


  return 0;
}