/*QUESTION:     https://leetcode.com/problems/binary-subarrays-with-sum/
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to the goal.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

APPROACH:
1. Create a helper function `answer(nums, goal)` that counts the number of subarrays having a sum at most `goal`.

2. Initialize two pointers `l` and `r` to maintain a sliding window, along with:
   * `sum` → current sum of the window.
   * `cnt` → number of subarrays whose sum is at most `goal`.

3. If `goal < 0`, return `0`. This is necessary because the array contains only non-negative elements, so no subarray can have a sum at most a negative value.

4. Iterate through the array using the right pointer `r`:
   * Add `nums[r]` to `sum`.
   * While `sum > goal`, move the left pointer `l` forward and subtract `nums[l]` from `sum` to restore the condition `sum <= goal`.
   * Once the window is valid, add `(r - l + 1)` to `cnt`.
   * This represents all valid subarrays ending at index `r`.
   * Move `r` to the next element.

5. The helper function therefore returns the number of subarrays with sum at most `goal`.

6. To count subarrays whose sum is exactly `goal`, use:
   `answer(nums, goal) - answer(nums, goal - 1)`.
   * `answer(nums, goal)` counts subarrays with sum `<= goal`.
   * `answer(nums, goal - 1)` counts subarrays with sum `<= goal - 1`.
   * Their difference gives the number of subarrays with sum exactly `goal`.

7. Return the calculated `ans`.

**Note:** This sliding-window approach works because the given array contains only non-negative elements (in this problem, binary values `0` and `1`). With negative numbers, increasing `r` or moving `l` would not provide the required monotonic behavior, so this approach would not be valid.
return cnt, which represents the number of non-empty subarrays with a sum equal to the goal.

CODE:*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int answer(vector<int> &nums, int goal)
    {
        int l = 0, r = 0, sum = 0, cnt = 0;
        if (goal < 0)
            return 0;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int ans = answer(nums, goal) - answer(nums, goal - 1);
        return ans;
    }
};

// COMPLEXITY ANALYSIS:
// - Time complexity: O(N),
// - Space complexity: O(1),
