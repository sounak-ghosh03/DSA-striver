/*
QUESTION: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

APPROACH:

Since the array is sorted and every element appears exactly twice except for one element, we can use **binary search** to find the single element in **O(log n)** time.

1. Let `n` be the size of the array.
2. Handle the edge cases:

   * If `n == 1`, return the only element.
   * If the first element is different from the second, return the first element.
   * If the last element is different from the second last, return the last element.
3. Initialize `low = 1` and `high = n - 2` since the boundary cases have already been checked.
4. While `low <= high`:

   * Compute `mid = low + (high - low) / 2`.
   * If `nums[mid]` is different from both its adjacent elements (`nums[mid-1]` and `nums[mid+1]`), then it is the single element. Return `nums[mid]`.
   * Otherwise, check whether `mid` is following the correct pairing pattern:

     * If `mid` is **odd** and `nums[mid] == nums[mid - 1]`, or
     * If `mid` is **even** and `nums[mid] == nums[mid + 1]`,
       then the single element lies on the **right** side, so update `low = mid + 1`.
     * Otherwise, the single element lies on the **left** side, so update `high = mid - 1`.
5. If no element is found (which should not happen for a valid input), return `-1`.



CODE:
*/
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 1, high = n - 2;

    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            return nums[mid];
        else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                 (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)
