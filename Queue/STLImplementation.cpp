#include <iostream>
using namespace std;

class Queue{
  public:
  int *arr;
  int size;
  int front;
  int back;

  Queue(int size){
    arr = new int[size];
    this->size = size;
    front = -1;
    back = -1;
  }

  void push(int data){
    //check for full
    if(back == size-1){
      cout<<"overflow condition"<<endl;
      return;
    }
    else if(front == -1 && back == -1){
      //check for empty case
      front++;
      back++;
      arr[back] = data;
    } 
    else{
      //normal case
      back++;
      arr[back] = data;
    }
  }

  void pop(){
    //check for empty
    if(front == -1 && back == -1){
      cout<<"queue underflow"<<endl;
      return;
    }
    else if(front == back){
      //1 element case
      arr[front] = -1;
      front = -1;
      back= -1;
    }
    else{
      //normal case
      arr[front] = -1;
      front++;
    }
  };

  bool isEmpty(){
    if(front == -1 && back == -1){
      return true;
    }
    else{
      return false;
    }
  }

  int getSize(){
    return back-front + 1;
  }

  int getFront(){
    if(front== -1){
      cout<<"queue is empty"<<endl;
      return -1;
    } else{
      return arr[front];

    }
  }

  void print(){
    for(int i=0; i<size; i++){
      cout<<arr[i]<<" ";
    } cout<<endl;
    cout<<endl;
  }
    
};

int main() {
  //creation in queue
  Queue q(5);
  q.print();

  q.push(10);
  q.print();

  q.push(20);
  q.print();

  q.push(30);
  q.print();

  q.push(40);
  q.print();

  q.push(50);
  q.print();

  // q.push(60);   overflow condition
  // q.print();

  cout<<q.getFront();
  cout<<endl;
  cout<<q.getSize();
  

  return 0;
}