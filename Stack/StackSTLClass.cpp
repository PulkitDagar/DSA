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

///second way
#include <iostream>
using namespace std;

class Stack{
  public:
  int* arr;
  int size;
  int top;

  Stack(int size){
    arr = new int[size];
    this->size = size;
    this->top = -1;
  };

  //insertion
  void push(int data){
    if(top==size-1){
      cout<<"Stack overflow"<<endl;
      return;
    }
    else{
      top++;
      arr[top] = data;
    }
    
  };

  void pop(){
    if(top==-1){
      cout<<"stack underflow"<<endl;
      return;
    } else{
      top--;
    }

  };

  bool isEmpty(){
    if(top==-1){
      return true;
    }
    else{
      return false;
    }
  };

  //return top element
  int getTop(){
    if(top==-1){
      cout<<"Stack is empty"<<endl;
      return -1;
    }
    else{
      return arr[top];
    }

  };

  int getSize(){
    return top+1;
  }

  void print(){
    cout<<"top"<<top<<endl;
    cout<<"gettop will be"<<getTop()<<endl;
    cout<<"stack:";
    for(int i=0; i<getSize(); i++){
      cout<<arr[i]<<" ";

    }
    cout<<endl;
  }
};

int main() {

  //creation
  Stack st(8);

  //push
  st.push(10);
  st.push(20);
  st.push(30);

  st.print();

  
  return 0;
}