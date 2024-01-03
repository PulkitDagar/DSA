#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr, int start, int end, int target){
    //base case
    if(start>end){
        return -1;
    }

    int mid = start+(end -start)/2;

    if(arr[mid] == target){
        return mid;
    }


    ///baaki recursion sambhal lega


};

int main(){
    vector<int> v{10,20,30,40,60,70,90,99};
    int n = v.size();
    int target = 90;

    int start = 0;
    int end = n-1;

    int ans = binarySearch(v,end,target,start);

    cout<<" The index at which our target is present is "<<ans <<endl;

    return 0;
}