/*
Question: https://leetcode.com/problems/split-array-largest-sum/description/
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.

Example:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Approach:

* The problem can be solved using the **Binary Search** algorithm on the answer.
* The minimum possible value of the largest subarray sum is the **maximum element** in the array because every subarray must contain at least one element.
* The maximum possible value of the largest subarray sum is the **sum of all elements** in the array because the entire array can be considered as one subarray.
* If `k` is greater than the size of the array, it is not possible to split the array into `k` non-empty subarrays, so return `-1`.
* Perform binary search in the range **[maximum element, sum of all elements]**.
* For each mid value, use a helper function to determine the **minimum number of subarrays** required such that the sum of each subarray does not exceed `mid`.
* The helper function traverses the array while maintaining the current subarray sum:

  * If adding the current element keeps the sum within `mid`, include it in the current subarray.
  * Otherwise, start a new subarray and increment the subarray count.
* If the required number of subarrays is **greater than `k`**, the current `mid` is too small, so search in the **right half** by setting `low = mid + 1`.
* Otherwise, the current `mid` is a valid answer, so try to minimize it further by searching in the **left half** using `high = mid - 1`.
* When the binary search ends, `low` represents the **minimum possible largest subarray sum**, which is returned as the final answer.


*/
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr, int parts)
{
    int posParts = 1, temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (temp + arr[i] <= parts)
        {
            temp += arr[i];
        }
        else
        {
            posParts++;
            temp = arr[i];
        }
    }
    return posParts;
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)

        return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = func(nums, mid);
        if (sum > k)
        {

            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

// Time Complexity: O(n * log(sum of array))
// Space Complexity: O(1)