#include <iostream>
using namespace std;
int fib(int n){
    //base case
    if(n==1){
        return 0;
    }

    if(n==2){
        return 1;
    }

    int ans  = fib(n-1) + fib(n-2);
    return ans;

}


int main(){

    int n = 5;
    cout<<" Enter the number to verify fibonacii to that place" <<endl;

    int ans = fib(n);
    cout<<" Our ans will be" <<ans <<endl;


    return 0;
}