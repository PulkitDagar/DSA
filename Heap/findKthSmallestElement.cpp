#include <iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k){
  //create a max heap
  priority_queue<int>pq;

  //starting k elements insert kro
  for(int i=0; i<k; i++){
    pq.push(arr[i]);
  };

  //for remaining elements check if it is greater than the top of max heap or not
  for(int i= k; i<n; i++){
    int element = arr[i];
    if(element < pq.top()){
      pq.pop();
      pq.push(element);
    }

  }

  int ans = pq.top();
  return ans;
}

int main() {
  int arr[] = {10,2,20,4,15};
  int n = 5;
  int k = 3;
  int ans = getKthSmallestElement(arr,n,k);

  cout<<"ans is "<<ans<<endl;
  return 0;
}