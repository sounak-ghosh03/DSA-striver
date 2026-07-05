/*
Question: https://leetcode.com/problems/longest-common-prefix/description/
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Approach:
1. Sort the array of strings lexicographically.
2. Take the first and last string from the sorted array.
3. Compare each character of the first and last string until they don't match or the end of either string is reached.
4. Return the common prefix.

Time Complexity: O(N*M*log(N)), where N is the number of strings and M is the maximum length of the strings.
- Sorting the array of strings takes O(N*log(N)) time.
- Comparing the first and last string takes O(M) time.

Space Complexity: O(1)
- We use constant space.
or O(M), where M is the maximum length of the common strings.

Code:
*/
#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int minlength = min(first.size(), last.size());
    string ans = "";
    for (int i = 0; i < minlength; i++)
    {
        if (first[i] != last[i])
            break;
        ans += first[i];
    }
    return ans;
}
