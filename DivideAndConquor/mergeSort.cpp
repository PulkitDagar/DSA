#include<iostream>
using namespace std;

void merge(int* arr, int start, int end){
    //now we have to create two new arrays
}

void mergeSort(int* arr, int start, int end){
    //base case
    //s==e return || s>e invalid index so return
    if(start>=end){
        return;
    }

    int mid = start+(end-start)/2;
    ///left part sort
    mergeSort(arr,start,mid);

    ///recursive call for right part
    mergeSort(arr,mid+1,end);

    merge(arr,start,end);

}

int main(){

    int arr[] = {4,13,5,2,9,2};
    int n = 6;

    int start = 0;
    int end = n-1;

    mergeSort(arr,start,end);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}