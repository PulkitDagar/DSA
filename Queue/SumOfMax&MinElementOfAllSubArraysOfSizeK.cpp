#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int sumOfMinMaxOfAllWindowOfSizeK(vector<int>& nums, int k) {
    deque<int> maxDeque, minDeque;
    int ans = 0;

    // Process first window
    for (int i = 0; i < k; ++i) {
        while (!maxDeque.empty() && nums[i] >= nums[maxDeque.back()]) {
            maxDeque.pop_back();
        }
        while (!minDeque.empty() && nums[i] <= nums[minDeque.back()]) {
            minDeque.pop_back();
        }
        maxDeque.push_back(i);
        minDeque.push_back(i);
    }

    ans += nums[maxDeque.front()] + nums[minDeque.front()];

    // Process the remaining windows
    for (int i = k; i < nums.size(); ++i) {
        // Remove elements out of the current window
        if (!maxDeque.empty() && maxDeque.front() <= i - k) {
            maxDeque.pop_front();
        }
        if (!minDeque.empty() && minDeque.front() <= i - k) {
            minDeque.pop_front();
        }

        // Remove smaller elements in maxDeque
        while (!maxDeque.empty() && nums[i] >= nums[maxDeque.back()]) {
            maxDeque.pop_back();
        }
        // Remove larger elements in minDeque
        while (!minDeque.empty() && nums[i] <= nums[minDeque.back()]) {
            minDeque.pop_back();
        }

        // Add the current element index
        maxDeque.push_back(i);
        minDeque.push_back(i);

        // Add the current window's min and max to the answer
        ans += nums[maxDeque.front()] + nums[minDeque.front()];
    }

    return ans;
}

int main() {
    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumOfMinMaxOfAllWindowOfSizeK(v, k) << endl;
    return 0;
}