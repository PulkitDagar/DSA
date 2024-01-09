#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    /// choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step2 find right position for pivot element and place it there
    int count = 0;
    for (int i =s+1; i<= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }

    // when we exit that loop so mere pass pivot ki right position ka index ready hai
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // step3: put smaller elements on left and bigger elements on right
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] <= pivotElement)
        {
            i++;
        }

        while (arr[j] > pivotElement)
        {
            j--;
        }

        // 2case ho skte hai
        // you found the element to swap
        // no need to swap

        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    // base case
    if (s>= e)
    {
        return;
    }

    // partition logic return pivotIndex
    int p = partition(arr, s, e);

    // recursive calls
    /// pivotelement left
    quickSort(arr, s, p-1);

    // pivot Element-> right
    quickSort(arr, p+1, e);
}
int main()
{

    int arr[] = {8, 3, 4, 1, 20, 50, 30};
    int n = 7;

    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);

    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}