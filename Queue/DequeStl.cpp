#include <iostream>
using namespace std;

class Deque{
  public:
  int *arr;
  int size;
  int front;
  int back;

  Deque(int size){
    arr = new int[size];
    this->size = size;
    front = -1;
    back = -1;
  }

  void pushBack(int data){
    //full
    if((front == 0 && back == size-1) || (back == front-1)){
      cout<<"over flow"<<endl;
      return;
    }
    //empty
    else if(back==-1 && front == -1){

      front++;
      back++;
      arr[back] = data;
    } 
    else if(back == size-1 && front!=0){
      back = 0;
      arr[back] = data;
    }
    else{
      back++;
      arr[back] = data;
    }
  };

  void pushFront(int data){
   //full
    if((front == 0 && back == size-1) || (back == front-1)){
      cout<<"over flow"<<endl;
      return;
    }
    else if(front == -1 && back == -1){
      front++;
      back++;
      arr[front] = data;
    }
    else if(front ==0 && back!= size-1){
      front = size-1;
      arr[front] = data;
    }
    else{
      front --;
      arr[front] =data;
    }
  };



  void popFront(){
     if(back==-1 && front == -1){
      cout<<"underflow"<<endl;
      return;
    }
    //single element
    else if(front == back){
      arr[front] = -1;
      front= -1;
      back = -1;

    }
    //circular
    else if(front == size-1){
      arr[front] = -1;
      front = 0;
    }
    else{
      arr[front] = -1;
      front++;
    }
  };

  void popBack(){
    //underflow
    if(front == -1 && back == -1){
      cout<<"underflow"<<endl;
      return;
    }
    else if(front == back){
      arr[back] = -1;
      front = -1;
      back = -1;
    }
    else if(back ==0){
      arr[back] = -1;
      back = size-1;
    }
    else{
      arr[back] = -1;
      back --;
    }

  };
};

int main(){
    Deque dq(5);
}