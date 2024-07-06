//based on sliding window pattern
#include <iostream>
#include<deque>
using namespace std;

void printFirstNegative(int *arr, int size, int k){
  //make a new queue
  deque<int>dq;

  //process first k element
  for(int index=0; index<k; index++){
    int element = arr[index];
    if(element<0){
      dq.push_back(index);
    }
  };

  //process remaining windows
  for(int index = k; index<size; index++){

    //aage badhne se phele purani window ka answer nikal lo
    if(dq.empty()){
      cout<<"0"<<endl;
      return;
    }
    else{
      cout<<arr[dq.front()]<<" ";
    }

    //removal jo bhi index out of range hai usko remove krdo queue se
    if(index - dq.front() >=k){
      dq.pop_front();
    }
    if(arr[index] < 0){
      dq.push_back(index);
    }
  }
  //last window ka answer print krdo
  if(dq.empty()){
    cout<<"0"<<endl;
    return;
  }
  else{
    cout<<arr[dq.front()]<<" ";
  }

   
}

int main() {
  int arr[] = {2,-5,4,-1,-2,0,5};
  int size = 7;
  int k = 3;

  printFirstNegative(arr,size,k);
  return 0;
}