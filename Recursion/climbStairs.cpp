#include <iostream>
using namespace std;


int climbStairs(int n){
    ///base case
    if(n==0 || n==1){
        return 1;
    }

    //recursive relation
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;

}

int main(){
    int n = 5;
    
    int ans = climbStairs(n);

    cout<<" The steps needeed to reach their destination"<<ans <<endl;


    return 0;
}