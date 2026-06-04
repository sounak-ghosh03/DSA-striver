/*
QUESTION: https://leetcode.com/problems/majority-element-ii/description/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]
*/
// better approach
#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> v)
{
    vector<int> ls;
    map<int, int> mpp;

    int n = v.size();
    int mini = (int)(n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;

        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}

/*
OPTIMIZED APPROACH:
To find all elements that appear more than ⌊ n/3 ⌋ times, we can use the Boyer-Moore Majority Vote algorithm.
This algorithm helps us find potential candidates that could appear more than ⌊ n/3 ⌋ times in a single pass.
After finding the candidates, we count their occurrences and return the elements that meet the criteria.

1. Initialize two potential majority elements, `el1` and `el2`, with `INT_MIN`, and their corresponding counters `cnt1` and `cnt2` to `0`.
2. Traverse the array and apply the extended Boyer-Moore Voting Algorithm:
   * If the current element is equal to `el1`, increment `cnt1`.
   * Else if the current element is equal to `el2`, increment `cnt2`.
   * Else if `cnt1` is `0`, assign the current element to `el1` and set `cnt1 = 1`.
   * Else if `cnt2` is `0`, assign the current element to `el2` and set `cnt2 = 1`.
   * Otherwise, decrement both `cnt1` and `cnt2`.

3. After the first traversal, `el1` and `el2` represent the two possible candidates that may occur more than ⌊n/3⌋ times.
4. Reset `cnt1` and `cnt2` to `0`, then traverse the array again to count the actual occurrences of `el1` and `el2`:
   * If an element equals `el1`, increment `cnt1`.
   * Else if it equals `el2`, increment `cnt2`.
5. Compute the threshold `mini = nums.size() / 3`.
6. Create a result vector `ls`:
   * If `cnt1 > mini`, add `el1` to `ls`.
   * If `cnt2 > mini`, add `el2` to `ls`.
7. Sort the result vector to maintain ascending order.
8. Return `ls`, which contains all elements appearing more than ⌊n/3⌋ times in the array.

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> nums)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
        {
            cnt1++;
        }
        else if (nums[i] == el2)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            el1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            el2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
    }

    vector<int> ls;
    int mini = nums.size() / 3;
    if (cnt1 > mini)
        ls.push_back(el1);
    if (cnt2 > mini)
        ls.push_back(el2);

    sort(ls.begin(), ls.end());
    return ls;
}

// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space.
