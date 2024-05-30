#include <iostream>
#include <vector>
using namespace std;

void solve(int arr[], int size, int i , vector<int> &ans){

  //base case
  if(i>=size){
    return;
  }

  //ek case
  if(arr[i]%2==0){
    ans.push_back(arr[i]);
  }

  //recursive call krdo
  solve(arr,size,i+1,ans);
}

int main() {
  ///if you given an array and whenever you encounter an even no in array store that into ans vector array
  int arr[7] = {2,3,4,5,6,7,8};
  int size = 7;
  int i = 0;
  vector<int>ans;
  solve(arr,size,i,ans);

  for(int num:ans){
    cout<<num<<" ";
  }
  return 0;
}