/*
Question: https://leetcode.com/problems/kth-missing-positive-number/description/
Given a sorted array arr of positive integers and an integer k, find the kth positive integer that is missing from the array.

Example:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Approach:
* Use binary search to find the last index where the number of missing positive integers is less than `k`.
* Initialize two pointers:

  * `low = 0` (start of the array)
  * `high = arr.size() - 1` (end of the array)
* While `low <= high`:

  * Compute the middle index `mid`.
  * Calculate the number of missing positive integers before `arr[mid]` as:

    missingNum = arr[mid] - (mid + 1)
  * If `missingNum < k`, move the search to the right by setting `low = mid + 1`.
  * Otherwise, move the search to the left by setting `high = mid - 1`.
* After the binary search, `high` represents the last index where the count of missing positive integers is less than `k`.
* The kth missing positive integer is then calculated as:

  k + high + 1 or low + k

  */
#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
  int low = 0, high = arr.size() - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int missingNum = arr[mid] - (mid + 1);
    if (missingNum < k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return 1 + k + high;
}
// Time Complexity: O(log n), where n is the size of the array.
// Space Complexity: O(1)