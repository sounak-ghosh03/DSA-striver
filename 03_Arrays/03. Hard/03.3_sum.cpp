/*
QUESTION: https://leetcode.com/problems/3sum/description/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/
#include <bits/stdc++.h>

using namespace std;

// brute force

vector<vector<int>> triplet(int n, vector<int> &num)
{

    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (num[i] + num[j] + num[k] == 0)
                {
                    vector<int> temp = {num[i], num[j], num[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

// better USING HASHING
vector<vector<int>> triplet(int n, vector<int> &num)
{

    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(num[i] + num[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {num[i], num[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}
/*
OPTIMIZED APPROACH:
1. Sort the given array in non-decreasing order.
2. Iterate through the array using index `i`, considering `arr[i]` as the first element of the triplet.
3. To avoid duplicate triplets, skip the current iteration if `arr[i]` is the same as the previous element.
4. For each fixed element `arr[i]`, initialize two pointers:
   * `j = i + 1` (left pointer)
   * `k = n - 1` (right pointer)
5. While `j < k`:
   * Compute `sum = arr[i] + arr[j] + arr[k]`.
   * If `sum < 0`, increment `j` to increase the sum.
   * If `sum > 0`, decrement `k` to decrease the sum.
   * If `sum == 0`, a valid triplet is found:
     * Store the triplet `{arr[i], arr[j], arr[k]}` in the answer.
     * Move both pointers inward (`j++`, `k--`).
     * Skip duplicate values at `j` and `k` to ensure unique triplets.
6. Continue the process until all possible triplets have been checked.
7. Return the list of unique triplets whose sum is zero.

*/
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1])
                    j++;

                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
        }

    return ans;
}

/*
TIME COMPLEXITY: O(n^2), where n is the size of the input array.
The sorting step takes O(n log n), and the two-pointer traversal takes O(n^2) in the worst case.
Hence, the overall time complexity is O(n^2).

SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space for storing the output and variables.
*/
