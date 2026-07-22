/*
QUESTION:
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Example 1:

Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4.
The original sorted array is 1 2 3 4 5.
We can see that the array was rotated
1 times to the right.

APPROACH:

To find the value of **K** (the number of rotations), we need to find the index of the smallest element in the rotated sorted array.

1. Initialize `low = 0` and `high = N - 1`.
2. Maintain two variables:
   * `ans` to store the minimum element found so far.
   * `index` to store the index of the minimum element.

3. While `low <= high`:
   * Compute `mid = low + (high - low) / 2`.
   * If the left half (`arr[low]` to `arr[mid]`) is sorted (`arr[low] <= arr[mid]`):
     * Compare `arr[low]` with `ans`. If it is smaller, update `ans` and `index`.
     * Since the left half is sorted, the minimum element (if not already found) must lie in the right half, so set `low = mid + 1`.
   * Otherwise, the rotation point lies in the left half (including `mid`):
     * Compare `arr[mid]` with `ans`. If it is smaller, update `ans` and `index`.
     * Move to the left half by setting `high = mid - 1`.

4. After the loop ends, `index` stores the position of the smallest element, which is equal to the number of rotations `K`.
5. Return `index`.


CODE:
*/
#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)
