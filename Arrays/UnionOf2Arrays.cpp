#include <vector>
#include <algorithm>

using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    vector<int> ans;

    // Sort both arrays
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int i = 0, j = 0;

    // Merge the two sorted arrays
    while (i < n && j < m) {
        // Add unique elements to the answer
        if (arr1[i] < arr2[j]) {
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (ans.empty() || ans.back() != arr2[j]) {
                ans.push_back(arr2[j]);
            }
            j++;
        } else {
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < n) {
        if (ans.empty() || ans.back() != arr1[i]) {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements from arr2
    while (j < m) {
        if (ans.empty() || ans.back() != arr2[j]) {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}
