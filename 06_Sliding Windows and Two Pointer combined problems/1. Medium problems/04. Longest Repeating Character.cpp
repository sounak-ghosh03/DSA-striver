/*QUESTION: https://leetcode.com/problems/longest-repeating-character-replacement/description/
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

APPROACH:
1. Initialize two pointers `l` and `r` to represent the left and right boundaries of the sliding window. Also initialize:
   - `maxlen` to store the maximum valid substring length.
   - `maxf` to store the highest frequency of any character in the current window.
   - `hash[26]` to store the frequency of each uppercase English letter.

2. Expand the window by moving `r` from left to right:
   - Increment the frequency of `s[r]` in `hash`.
   - Update `maxf` with the maximum frequency of the current character.

3. Calculate the number of characters that need to be replaced:
   - `window length - maxf`
   - i.e. `(r - l + 1) - maxf`
   - If this value is greater than `k`, the current window is invalid.

4. If the window becomes invalid:
   - Decrease the frequency of `s[l]`.
   - Move `l` one position to the right.
   - The code resets `maxf` to `0`; as `r` continues moving, `maxf` is rebuilt from the newly encountered characters.

5. If the number of required replacements is at most `k`, update `maxlen` with the current window length.

6. Continue until `r` reaches the end of the string and return `maxlen`.

*/
// CODE:
// brute force

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> hash(26, 0);
            for (int j = i; j < n; j++)
            {
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                int length = j - i + 1;
                int change = length - maxFreq;

                if (change <= k)
                {
                    maxLen = max(maxLen, length);
                }
                else
                    break;
            }
        }
        return maxLen;
    }
};

// optimal
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, maxlen = 0, maxf = 0, n = s.size();
        int hash[26] = {0};
        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            if ((r - l + 1) - maxf > k)
            {
                hash[s[l] - 'A']--;
                l++;
                maxf = 0;
            }
            if ((r - l + 1) - maxf <= k)
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
- Time complexity: O(N), where N is the length of the string s and L is the number of unique letters in the string. We iterate through the string and perform the sliding window operation for each unique letter.
    - L can have the max value of 26, so we can say the complexity would be O(N * 26) i.e O(N).
- Space complexity: O(1), as we store the unique letters in the set ltrs.
*/
