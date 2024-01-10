//Print all permutation of string
//BackTracking is nothing but a specific form of recursion
#include<iostream>
using namespace std;

void printPermutation(string& str, int i){
    ///base case would be when we loop all the string
    if(i>=str.length()){
        cout<<str<<endl;
        return;
    }


    //we apply the swapping logic
    for(int j = i; j<str.length(); j++){
        swap(str[j],str[i]);

        ///as we already solve the one case so now we can make recursive calls
        printPermutation(str,i+1);


        //backtracking logic => to recreate the original string bcoz we send the string as pass by reference
        swap(str[j], str[i]);
    }
}
int main(){

    string str = "abc";
    int i = 0;

    printPermutation(str,i);
}