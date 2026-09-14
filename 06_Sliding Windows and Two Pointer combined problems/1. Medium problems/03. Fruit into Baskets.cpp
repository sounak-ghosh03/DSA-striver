/*QUESTION: https://leetcode.com/problems/fruit-into-baskets/
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits of size N, where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
1. You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
2. Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
3. Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: N = 3, fruits[] = {2, 1, 2}
Output: 3
Explanation: We can pick fruits from all three trees.

APPROACH:
**APPROACH:**

1. Initialize two pointers `l` and `r` to represent the current sliding window, a `maxlen` variable to store the maximum valid window length, and a `map` `mpp` to track the frequency of each fruit type in the current window.

2. Iterate through the array using the right pointer `r`:
   * Add `fruits[r]` to the map and increment its frequency.
   * If the window contains more than 2 distinct fruit types, decrement the frequency of `fruits[l]`.
   * If its frequency becomes `0`, erase it from the map.
   * Move the left pointer `l` one position forward to reduce the window.

3. Whenever the window contains at most 2 distinct fruit types, update `maxlen` with the maximum of its current value and the current window length `r - l + 1`.

4. Continue until `r` reaches the end of the array, then return `maxlen`.

KEY IDEA:
Use a sliding window containing at most 2 distinct fruit types. The right pointer expands the window, while the left pointer contracts it whenever a third fruit type is introduced.

*/

// brute force :
// - Use set to identify the unique elements in the array
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            set<int> st;
            for (int j = i; j < n; j++)
            {
                st.insert(fruits[j]);
                if (st.size() <= 2)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                    break;
            }
        }
        return maxLen;
    }
};

// close to optimal
#include <bits/stdc++.h>
using namespace std;
int totalFruits(int N, vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int ans = 0, start = 0;
    for (int i = 0; i < fruits.size(); i++)
    {
        mp[fruits[i]]++;
        while (mp.size() > 2)
        {
            mp[fruits[start]]--;
            if (mp[fruits[start]] == 0)
                mp.erase(fruits[start]);
            start++;
        }
        if (mp.size() <= 2)
            ans = max(ans, i - start + 1);
    }
    return ans;
}

// most optimal:
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int l = 0, r = 0, maxlen = 0, n = fruits.size();
        map<int, int> mpp;
        while (r < n)
        {
            mpp[fruits[r]]++;
            if (mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                l++;
            }
            if (mpp.size() <= 2)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};
/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N), where N is the number of fruit trees. We iterate through the fruit trees once using the sliding window approach.
- Space complexity: O(1) or O(2), as the size of the map can be at most 2 since we only have two baskets.
*/
