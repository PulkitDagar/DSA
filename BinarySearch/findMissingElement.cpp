#include <iostream>
using namespace std;

int findMissingElement(int arr[], int n){
  int start = 0;
  int end = n-1;
  int mid = start + (end-start)/2;
  int ans = -1;

  while(start<=end){
    int difference = arr[mid] - mid;
    if(difference == 1){
      //right mai jao
      start = mid+1;
    }
    else{
      //ans store krlo or right mee jao
      ans = mid;
      end = mid -1;
    }
    mid = start + (end-start)/2;
  }
  return ans+1;
}

int main() {
  //find the element is present or not using binary search
  int arr[] = {1,2,3,4,6,7,8,9};
  int n = 8;

  cout<<findMissingElement(arr,n);
  return 0;
}