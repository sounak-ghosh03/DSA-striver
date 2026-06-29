/*QUESTION: https://leetcode.com/problems/maximum-product-subarray/description/

Given an integer array nums, find a subarray that has the largest product, and return the product.

Example:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

APPROACH:

To find the subarray with the largest product, we iterate through the array while keeping track of the current product. We maintain two variables: `ans` to store the maximum product found so far and `prdct` to store the current product. Since negative numbers can change the sign and potentially result in a larger product, we run the loop twice, once from left to right and once from right to left.

CODE:*/
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int ans = INT_MIN;
    int prdct = 1;

    // Iterate from left to right
    for (int i = 0; i < nums.size(); i++)
    {
        prdct = prdct * nums[i];
        ans = max(ans, prdct);
        if (prdct == 0)
            prdct = 1;
    }

    prdct = 1;

    // Iterate from right to left
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prdct = prdct * nums[i];
        ans = max(ans, prdct);
        if (prdct == 0)
            prdct = 1;
    }

    return ans;
}

/*
TIME COMPLEXITY: O(N), where N is the size of the input array.
SPACE COMPLEXITY: O(1).
*/

// Another OPTIMAL approach:

class Solution
{
public:
    // This function returns the maximum product
    // of any contiguous subarray using optimized approach
    int maxProduct(vector<int> &nums)
    {
        // Initialize answer, max and min product as first element
        int res = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        // Traverse from second element
        for (int i = 1; i < nums.size(); i++)
        {
            // Store current number
            int curr = nums[i];

            // If current number is negative, swap max and min
            if (curr < 0)
                swap(maxProd, minProd);

            // Update max and min product ending at current index
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            // Update global result
            res = max(res, maxProd);
        }

        // Return the result
        return res;
    }
};
// Time Complexity: O(N), every element of array is visited once.
// Space Complexity: O(1) , only constant variables are used.
