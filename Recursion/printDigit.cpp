#include<iostream>
using namespace std;

void printDigit(int n){
    ///base case
    if(n==0){
        return;
    }

    int newValOfN = n/10;
    printDigit(newValOfN);

    int digit = n%10;
    cout<<digit<<" ";

}
int main(){
    int n = 647;

    printDigit(n);


    return 0;
}