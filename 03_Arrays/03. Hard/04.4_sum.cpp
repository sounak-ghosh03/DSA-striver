/*
QUESTION: https://leetcode.com/problems/4sum/description/
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/
// brute force
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// better

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;

                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
/*
APPROACH:
To find the unique quadruplets that sum up to the target, we can use a similar approach as the threeSum problem.
We will fix two elements (nums[a] and nums[b]) and use two pointers to find the remaining two elements (nums[c] and nums[d]) that sum up to the target.

1. Sort the given array in non-decreasing order.
2. Use two nested loops to fix the first two elements of the quadruplet:
   * Let `nums[i]` be the first element.
   * Let `nums[j]` be the second element.
3. To avoid duplicate quadruplets:
   * Skip the current iteration of `i` if `nums[i]` is the same as the previous element.
   * Skip the current iteration of `j` if `nums[j]` is the same as the previous element for the same `i`.
4. For each pair `(nums[i], nums[j])`, initialize two pointers:
   * `k = j + 1` (left pointer)
   * `l = n - 1` (right pointer)
5. While `k < l`:
   * Calculate `sum = nums[i] + nums[j] + nums[k] + nums[l]`.
   * If `sum == target`:
     * A valid quadruplet is found.
     * Store `{nums[i], nums[j], nums[k], nums[l]}` in the answer.
     * Move both pointers inward (`k++`, `l--`).
     * Skip duplicate values at `k` and `l` to ensure unique quadruplets.
   * If `sum < target`, increment `k` to increase the sum.
   * If `sum > target`, decrement `l` to decrease the sum.
6. Continue until all possible quadruplets have been checked.
7. Return the list of unique quadruplets whose sum equals the target.


CODE:
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++, l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }

    return ans;
}

/*
TIME COMPLEXITY: O(n^3), where n is the size of the input array nums.
SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space.
*/
