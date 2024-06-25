#include <iostream>
using namespace std;

class Stack {
  public:
  int *arr;
  int top;
  int size;

  Stack(int size){
    arr = new int[size];
    this->size = size;
    top = -1;
  }

  //functions
  void push(int data){
    if(size-top>1){
      //means space is available
      //insert
      top++;
      arr[top] = data;
    }
    else{
      //space not available
      cout<<"stack overflow"<<endl;
    }
  };

  void pop(){
    if(top == -1){
      //stack is empty
      cout<<"stack underflow, can't delete element"<<endl;
    }
    else{
      top--;
    }
  };

  int getTop(){
    if(top == -1){
      cout<<"There is no element in stack"<<endl;
    }
    else{
      return arr[top];
    }
    
  };

  //no of valid elements present in stack
  int getSize(){
    return top+1;
  };

  bool isEmpty(){
    if(top== -1){
      return true;
    }
    else{
      return false;
    }
  };
};

int main() {
  Stack s(10);

  //insertion
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);

  while(!s.isEmpty()){
    cout<<s.getTop()<<" ";
    s.pop();
  }
  
  return 0;
 
}