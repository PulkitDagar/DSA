//We have given a length N which represent rod length. We need to determine the maximum no 
//of segments we can make of this rod,provided that each segment should be of length x,y,z;
#include<iostream>
#include<limits.h>
using namespace std;

int solve(int N, int x, int y, int z){

    //base case
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