/*
Question: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
You are given an array of integers nums and an integer threshold. We need to find the smallest divisor
such that the result of dividing each element of the array by the divisor and summing up the results
is less than or equal to the threshold.

Example:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum of 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4, we can get a sum of 7 (1+1+2+3).
If the divisor is 5, the sum will be 5 (1+1+1+2).
The smallest divisor that gives a sum less than or equal to the threshold is 5.

Approach:
* Find the maximum element in the array. This value becomes the upper bound for the binary search since the divisor cannot be greater than the largest element.
* If the number of elements in the array is greater than the given `threshold`, return `-1` because the minimum possible sum (where each element contributes at least `1`) would already exceed the threshold.
* Initialize the binary search range with `low = 1` and `high = maximum element`.
* For each midpoint (`mid`) in the search range, calculate the sum of `ceil(nums[i] / mid)` for all elements in the array.
* If the calculated sum is less than or equal to the `threshold`, store the current divisor as a possible answer and continue searching in the left half (`high = mid - 1`) to find a smaller valid divisor.
* If the calculated sum is greater than the `threshold`, search in the right half (`low = mid + 1`) because a larger divisor is needed to reduce the sum.
* Continue the binary search until the search range is exhausted.
* Return the stored answer, which represents the smallest divisor that satisfies the given threshold condition.

Code:
*/
#include <bits/stdc++.h>
using namespace std;

// find the maximum element
int maxi(vector<int> &nums)
{
    int m = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        m = max(m, nums[i]);
    }
    return m;
}

// calculate the sum of divisions
long long sumofDigits(vector<int> &nums, int d)
{
    long long s = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        s += ceil((double)nums[i] / d);
    }
    return s;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;
    int low = 1, high = maxi(nums), ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumofDigits(nums, mid) <= threshold)
        {

            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// Time Complexity: O(n log(max(nums)))
// Space Complexity: O(1)
