/*
QUESITON:- https://leetcode.com/problems/two-sum/description/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/
// brute force
#include <bits/stdc++.h>
using namespace std;
pair<int, int> twoSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// BETTER APPROACH USING HASHING(also this is the best approach if index is asked to return)
/*
--> Create a map to store numbers and their indices
As you traverse the array, keep each number with its index in mpp.
--> For every element, find the needed complement
Compute:
more=target−nums[i]
--> Then check if more is already present in the map.
Return indices if complement exists; otherwise store current number
If found → return {index_of_complement, current_index}
Else → store current number and continue scanning.
*/
#include <bits/stdc++.h>
using namespace std;
pair<int, int> twoSumBetterWay(int arr[], int n, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end())
        {
            return {mpp[more], i};
        }
        mpp[a] = i;
    }
    return {-1, -1};
}

// TIME COMPLEXITY = O(N LOG N)
// SPACE COMPLEXITY = O(N)


// slightly better/optimal approach (only yes/no answer is asked)

string twoSumBetter(vector<int> arr, int n, int target)
{
    int left = 0, right = n - 1;
    sort(arr.begin(), arr.end());

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "Yes";
        }
        else if (sum < target)
            left++;
        else
            left--;
    }
    return "No";
}


// If the question asks to just return whether pair exists or not, not the indexes in that case we can sort and easily find the pair sum without extra space

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)