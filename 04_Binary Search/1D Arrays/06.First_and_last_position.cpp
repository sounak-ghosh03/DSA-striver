/*
QUESTION: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

APPROACH:
1. Use lower_bound to find the index of the first occurrence of the target in the array.
2. If the target is not found, return [-1, -1].
3. Use upper_bound to find the index of the last occurrence of the target in the array.
4. Return the range [first, last-1] as the starting and ending positions.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    // if the target is not found, return [-1, -1]
    if (first == nums.size() || nums[first] != target)
        return {-1, -1};
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return {first, last - 1};
}

// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)

// ALTERNATIVE APPROACH
//* plain code

#include <bits/stdc++.h>

// first occurance

int firstOccurance(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

// last occurance

int lastOccurance(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurance(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurance(arr, n, k);
    return {first, last};
}
