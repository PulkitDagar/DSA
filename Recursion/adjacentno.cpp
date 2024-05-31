//suppose we have an aray 1,2,3 so the position of them is changed from their previous postion after we find permutation
///  adjacent
#include <iostream>
using namespace std;
int solve(int n){
  //base case
  if(n==1){
    return 0;
  }
  if(n==2){
    return 1;
  }
  //n-1 means ki 1 ko rakhne k n-1 ways hai hmare pass
  ///n-2 means when we swap 1 and i(second no) and consider 1 and i condition as find
  //n-1 means when we just put 1 at place of 1 but didn't put i at the place of 1
  int ans = (n-1) * (solve(n-1)+ solve(n-2));
  return ans;

}

int main(){
  int n = 4;
  cout<<solve(n)<< endl;
}