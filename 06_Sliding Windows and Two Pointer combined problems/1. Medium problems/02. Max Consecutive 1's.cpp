/*QUESTION: https://leetcode.com/problems/max-consecutive-ones-iii/description/
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/
// brute force solution:
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int zeros = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                {
                    zeros++;
                }
                if (zeros <= k)
                {
                    int len = j - i + 1;
                    maxLen = max(len, maxLen);
                }
                else
                    break;
            }
        }
        return maxLen;
    }
};
/*
OPTIMAL APPROACH:
1. Initialize variables `l`, `r`, `maxlen`, and `zeroes`.
   * `l` → left/start index of the sliding window
   * `r` → right/end index
   * `zeroes` → number of zeros in the current window
   * `maxlen` → maximum valid window length found

2. Iterate through the array using `r`:
   * If `nums[r] == 0`, increment `zeroes`.
   * If `zeroes > k`, move the left pointer `l` forward by one position.
   * If `nums[l] == 0`, decrement `zeroes` before moving `l`.

3. If the current window contains at most `k` zeros:
   * Calculate its length as `r - l + 1`.
   * Update `maxlen` with the maximum of the current `maxlen` and the current window length.

4. Increment `r` and continue until the entire array is processed.

5. Return `maxlen`, which represents the maximum length of a subarray containing at most `k` zeros, i.e. the longest sequence of 1s obtainable by flipping at most `k` zeros.

That said, the more conventional sliding-window implementation uses `while (zeroes > k)`, because it guarantees the window is immediately valid after shrinking. In this particular problem, the given `if` version still works because the window can only gain **one zero per iteration**.

CODE:*/

// optimal:
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        int l = 0;
        int zeros = 0;

        for (int r = 0; r < n; ++r)
        {
            if (nums[r] == 0)
                zeros++;

            while (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

// most optimal: lil minor change
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, maxlen = 0, zeroes = 0;
        int n = nums.size();
        while (r < n)
        {
            if (nums[r] == 0)
                zeroes++;
            if (zeroes > k)
            {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }
            if (zeroes <= k)
            {
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N), where N is the length of the input array nums. We iterate through the array once.
- Space complexity: O(1), as we are using a constant amount of additional space to store variables.
*/
