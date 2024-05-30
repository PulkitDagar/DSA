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

// void printDigits(int num){
//     //base case
//     if(num==0){
//         return;
//     }

//     int digit = num%10;
//     //update num
//     num = num/10;
//     //recursive call
//     printDigits(num);

//     //processing
//     cout<<digit<<endl;
// }


int main(){
    int n = 647;

    printDigit(n);


    return 0;
}