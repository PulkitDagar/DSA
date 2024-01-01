#include <iostream>
using namespace std;

int factorial( int n) {
    //base case
    if(n==1){
        return 1;
    }

    //recursive call
    int smallFact = n * factorial(n-1);

    return smallFact;
}

int main() {
    int n = 5;
    cout<<" Enter the number" <<endl;
    

    int ans = factorial(n);
    cout<<" The answer of given output is "<<ans<<endl;

    return 0;
    
}