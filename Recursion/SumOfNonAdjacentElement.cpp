#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>& arr, int i, int sum, int &maxi){
    //base case
    if(i>arr.size()){
        maxi = max(sum,maxi);
        return;
    }
    //ek case solve kro baaki recursion sambhal lega
}
int main(){
    vector<int>arr{1,2,3,5,4};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solve(arr,i,sum,maxi);

    cout<<maxi<<endl;

    return 0;
}