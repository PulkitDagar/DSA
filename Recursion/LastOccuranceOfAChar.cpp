//We have given a string = "abcddefg" and also a char x = 'd' we need to find the last 
//occurance of d in that string

#include<iostream>
#include<string>
using namespace std;

void lastOccLTR(string &s, char x, int i, int &ans){

    //base case
    if(i>= s.size()){
        return;
    }

    //ek case solve krdo baaki recurion sambhal lega
    if(s[i]==x){
        ans =i;
    }

    //RR
    lastOccLTR(s,x,i+1,ans);
}

int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;

    int ans = -1;
    lastOccLTR(s,x,0,ans);

    cout<<ans<<endl;


    return 0;
}