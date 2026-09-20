/*
QUESTION: https://leetcode.com/problems/count-number-of-nice-subarrays/
Given an array of integers nums and an integer k, a continuous subarray is called nice if there are k odd numbers in it. Return the number of nice subarrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only subarrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

APPROACH:
1. Define a helper function called `answer`, which calculates the number of subarrays containing at most `goal` odd numbers.

2. Initialize:
   * `l` → left pointer of the sliding window.
   * `r` → right pointer used to traverse the array.
   * `sum` → number of odd elements currently present in the window.
   * `cnt` → number of valid subarrays with at most `goal` odd numbers.

3. If `goal < 0`, return `0`, since a subarray cannot contain a negative number of odd elements.

4. Iterate through the array using the right pointer `r`:
   * Convert `nums[r]` into `1` if it is odd and `0` if it is even, using `(nums[r] % 2 ? 1 : 0)`, and add it to `sum`.
   * While `sum > goal`, move the left pointer `l` forward and subtract the odd/even contribution of `nums[l]` from `sum`. This ensures that the current window contains at most `goal` odd numbers.
   * Add `(r - l + 1)` to `cnt`, representing the number of valid subarrays ending at index `r`.
   * Increment `r`.

5. Return `cnt`, which represents the total number of subarrays containing at most `goal` odd numbers.

6. In `numberOfSubarrays`, calculate the number of subarrays containing **exactly `k` odd numbers using:
   `answer(nums, k) - answer(nums, k - 1)`
   * `answer(nums, k)` counts subarrays with at most `k` odd numbers.
   * `answer(nums, k - 1)` counts subarrays with at most `k - 1` odd numbers.
   * Their difference gives the number of subarrays containing exactly `k` odd numbers, i.e., the number of **nice subarrays.

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
            sum += (nums[r] % 2 ? 1 : 0);
            while (sum > goal)
            {
                sum -= (nums[l] % 2 ? 1 : 0);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return answer(nums, k) - answer(nums, k - 1);
    }
};

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N)
- Space complexity: O(1)
*/
