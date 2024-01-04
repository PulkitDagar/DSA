//We have given a length N which represent rod length. We need to determine the maximum no 
//of segments we can make of this rod,provided that each segment should be of length x,y,z;
#include<iostream>
#include<limits.h>
using namespace std;

int solve(int N, int x, int y, int z){

    //base case
    if(N == 0){
        return 0;
    }

    if(N<0){
        return INT_MIN;
    }

    //ek case solve kro baaki recursion sambhal lega
    int ans1 = solve(N-x, x, y, z)+1;
    int ans2 = solve(N-y,x,y,z)+1;
    int ans3 = solve(N-z,x,y,z)+1;

    int ans = max(ans1, max(ans2, ans3));

    return ans;
}

int main(){
    int N = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(N,x,y,z);
    if(ans<0){
        ans = 0;
    }

    cout<<"Our answer will be"<<ans<<endl;

    return 0;

}