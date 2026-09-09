/*
Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Given a string s, find the length of the longest substring without repeating characters.
Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


CODE:-
*/
// brute force solution:
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLen = 0;
        unordered_map<char, bool> hash;

        for (int i = 0; i < n; i++)
        {
            hash.clear();
            for (int j = i; j < n; j++)
            {
                if (hash[s[j]])
                    break;
                int length = j - i + 1;
                maxLen = max(length, maxLen);
                hash[s[j]] = true;
            }
        }
        return maxLen;
    }
};

/* Optimal Approach:

* We can use a **sliding window / two-pointer approach** to solve this problem.
* We maintain a window from index `l` to `r` that contains **only unique characters**.
* We use a `vector<int> hash(256, -1)` to store the **last index at which each character was seen**.
* Initially, both pointers `l` and `r` are set to `0`, and every character's last-seen index is initialized to `-1`.
* We iterate through the string using the right pointer `r`, expanding the window one character at a time.
* For the current character `s[r]`, we check `hash[s[r]]`:

  * If it is `-1`, the character has not appeared before.
  * If it has appeared before **inside the current window** (`hash[s[r]] >= l`), we move `l` directly to `hash[s[r]] + 1` to exclude the previous occurrence.
* We then calculate the current window length using `r - l + 1` and update `maxLen` if this window is larger.
* Finally, we update the last-seen index of the current character with `hash[s[r]] = r` and move `r` forward.
* Since the left pointer jumps directly to the required position instead of shrinking the window one character at a time, the algorithm efficiently finds the length of the longest substring without repeating characters.
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLen = 0;
        vector<int> hash(256, -1);
        int l = 0, r = 0;

        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                if (hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

/*
Complexity Analysis
-Time Complexity: `O(N)`, where `N` is the length of the string. Each character is processed once by the right pointer, and the left pointer only moves forward.
-Space Complexity: `O(256)`, which is effectively **O(1)**, because the `hash` vector has a fixed size of 256 to store the last-seen index of each possible character.
*/
