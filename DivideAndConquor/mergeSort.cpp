#include<iostream>
using namespace std;

void merge(int* arr, int start, int end){
    //now we have to create two new arrays
    int mid = start+(end-start)/2;

    int len1 = mid-start+1;
    int len2 = end-mid;

    //now we creae 2 arrays for lengthl1 and lengthl2
    int* left = new int[len1];
    int* right = new int[len2];

    // copy values
    int k = start;
    for(int i = 0; i<len1; i++){
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0; i<len2; i++){
        right[i] = arr[k];
        k++;
    };

    //merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while(leftIndex<len1 && rightIndex<len2){

        if(left[leftIndex]<right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }

        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    };


    ///if the element are reached in one of the array so copy othe elements of array directly
    while(leftIndex<len1){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    while(rightIndex<len2){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }


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

    int arr[] = {4,13,17,55,24,9,2};
    int n = 7;

    int start = 0;
    int end = n-1;

    mergeSort(arr,start,end);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}