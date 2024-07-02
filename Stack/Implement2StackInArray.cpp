#include <iostream>
using namespace std;

class Stack{
  public:
  int* arr;
  int size;
  int top1;
  int top2;

  Stack(int size){
    arr = new int[size];
    this->size = size;
    top1 = -1;
    top2 = size;
  };

  void push1(int data){
    if(top2-top1==1){
      //no space available
      cout<<"Overflow condition"<<endl;
    } else{
      top1++;
      arr[top1] = data;
    }
   
  };

  void push2(int data){
    if(top2-top1==1){
      //no space available
      cout<<"Overflow condition"<<endl;
    } else{
      top2--;
      arr[top2] = data;
    }
    
  }

  void pop1(){
    if(top1 == -1){
      cout<<"underflow condition"<<endl;
    } else{
      arr[top1] =0;
      top1--;
    }
    
  };

  void pop2(){
    if(top2 == size){
      cout<<"underflow"<<endl;
    } else{
      arr[top2] = 0;
      top2 ++;
    }
   
  };

  ///generally hota nhi hai but void function 
  void print(){
    cout<<endl;
    cout<<"top1"<<top1<<endl;
    cout<<"top2"<<top2<<endl;

    for(int i=0; i<size; i++){
      cout<<arr[i]<<' ';
    }
    cout<<endl;
  }
};

int main() {
  Stack st(8);
  st.print();

  st.push1(3);
  st.print();
  return 0;
}