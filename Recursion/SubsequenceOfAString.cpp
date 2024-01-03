///Subsequence basically means we have to print all possible sequences of a given string but the order should
//be preserved
#include<iostream>
using namespace std;

void printSubSequence(string str, string output, int i){

    ///basecase
    if(i>= str.length()){
        cout<<output<<endl;
        return;
    }

    //ek case solve krdo
    //here we use the famous pattern which is include and exclude
    //exclude
    printSubSequence(str,output,i+1);


    //include
    output.push_back(str[i]);
    printSubSequence(str,output,i+1);
}


int main(){

    string str = "abc";
    string output = "";
    int i = 0;

    printSubSequence(str,output,i);

   

}