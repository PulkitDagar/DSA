#include<iostream>
using namespace std;

bool checkKey(string str, int i, int n, char key){
    //base case
    if(i>=n){
        return false;
    }

    //recursive case
    if(str[i] == key){
        return true;
    }

    //baaki recursion sambhal lega
    bool ans = checkKey(str,i+1,n,key);
    return ans;
}
int  main(){

    ///find the given key in an string
    string str = "Pulkitdagar";
    int n = str.length();
    char key = 'a';

    int i = 0;
    bool ans = checkKey(str,n,i,key);

    cout<<"answer will be"<<ans<<endl;

    return 0;
}