/*
QUESTION:- https://leetcode.com/problems/find-peak-element/description/
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/

/*
APPROACH:-
We can use the binary search approach to find a peak element.

1. If the array contains only one element, return index `0`.
2. Check the boundary elements:
   * If the first element is greater than the second, return index `0`.
   * If the last element is greater than the second last, return index `n-1`.
3. Initialize `low = 1` and `high = n-2` since the boundary elements have already been checked.
4. While `low <= high`:
   * Calculate `mid = low + (high - low) / 2`.
   * If `nums[mid]` is greater than both its left and right neighbors, then `mid` is a peak element. Return `mid`.
   * If `nums[mid] > nums[mid-1]`, it means we are on the increasing slope, so move to the right by setting `low = mid + 1`.
   * Otherwise, move to the left by setting `high = mid - 1`.

CODE:-
*/
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 1, high = n - 2;
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)
