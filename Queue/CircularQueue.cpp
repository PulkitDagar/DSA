#include <iostream>
using namespace std;

class Cqueue{
  public:
  int *arr;
  int size;
  int front;
  int back;
  
  Cqueue(int size){
    arr = new int[size];
    this->size = size;
    front = -1;
    back = -1;
  };

  void push(int data){
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
  }

  void pop(){
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
  }

  void print(){
    for(int i=0; i<size; i++){
      cout<<arr[i]<<" ";
    } cout<<endl;
    cout<<endl;
  }
};

int main() {
  Cqueue q(5);
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

  q.push(60);

  q.pop();
  q.pop();
  q.pop();
  q.print();

  return 0;
}