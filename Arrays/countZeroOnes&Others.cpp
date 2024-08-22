#include <iostream>
using namespace std;


int main() {
  //check for zeroes and ones
  int arr[] = {1,0,1,1,1,0,0,0,1,1,0,1,2};
  int n = 13;

  int countZero = 0;
  int countOne = 0;
  int countOther = 0;

  for(int i=0; i<n; i++){
    if(arr[i]==0){
      countZero++;
    }
    else if(arr[i]==1){
      countOne++;
    }
    else{
      //what to write in else case suppose if a other no is present other than 0 and 1;
      countOther++;
      cout << "Error: Unexpected value " << arr[i] << " found at index " << i << endl;
    }
  }

  cout<<"the total no of zerors is"<<countZero<<" ";
  cout<<endl;
  cout<<"the total no of ones is "<<countOne<<" ";
  cout<<endl;

  if(countOther > 0) {
    cout << "The total number of unexpected values is " << countOther << endl;
  }
}