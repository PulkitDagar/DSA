class Solution
{
public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr)
    {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > largest)
            {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest && arr[i] < largest)
            {
                secondLargest = arr[i];
            }
        };

        if (secondLargest != INT_MIN)
        {
            return secondLargest;
        }
        else
        {
            return -1;
        }
    }
};