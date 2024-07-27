#include <iostream>
using namespace std;

class Heap{

  public:
  //we know hmm heap ko array se create krte hai
  int arr[25];
  int size;

  Heap(){
    size = 0;
  }

  void insertion(int value){
    //value insert kro end mai
    size = size+1;
    int index = size;
    arr[index] = value;

    //is value ko correct position per place kro
    while(index>1){
      int parentIndex = index/2;
      if(arr[index] > arr[parentIndex]){
        swap(arr[index], arr[parentIndex]);
        index = parentIndex;
      }
      else{
        break;
      }
    };
  };

  int deletion(){
    //replace root node value with last node data
    arr[1] = arr[size];
    size--;

    //place root node ka data on its current position
    int index = 1;
    while(index < size){
      int left = 2*index;
      int right = 2*index + 1;

      int largest = index;

      if(left < size && arr[largest] < arr[left]){
        largest = left;
      }
      if(right<size && arr[largest] < arr[right]){
        largest = right;
      }

      //ager value jo hai vo already correct address per hai(root per)
      if(largest == index){
        //value is at correct position
        return;
      }
      else{
        swap(arr[index], arr[largest]);
        index = largest;
      }
    }
  }
};




int main() {
  Heap h;
  h.arr[0] = -1;
  h.arr[1] = 100;
  h.arr[2] = 50;
  h.arr[3] = 60;
  h.arr[4] = 40;
  h.arr[5] = 45;

  h.size = 5;

  
  cout<<"printing the heap"<<endl;
  for(int i=0; i<=h.size; i++){
    cout<<h.arr[i]<<" ";
  }


  h.insertion(110);
  cout<<endl;
  cout<<"printing the heap"<<endl;
  for(int i=0; i<=h.size; i++){
    cout<<h.arr[i]<<" ";
  }
  return 0;
}