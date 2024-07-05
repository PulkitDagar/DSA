#include <iostream>
#include<deque>
using namespace std;

int main() {
  //creation
  deque<int> dq;

  //insertion
  dq.push_back(7);
  dq.push_front(10);

  cout<<dq.front()<<endl;
  cout<<dq.back()<<endl;

  cout<<dq.size()<<endl;


  return 0;
}