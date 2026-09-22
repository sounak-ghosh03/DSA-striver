/*
QUESTION: https://leetcode.com/problems/minimum-window-substring/
Given two strings 's' and 't' of lengths 'm' and 'n' respectively, find the minimum window substring of 's' that contains all the characters of 't' (including duplicates). If there is no such substring, return an empty string.

EXAMPLE:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string 't'.

APPROACH:
We can solve this problem using a sliding window / two-pointer approach.

1. **Initialize the function**
   * Create a function `minWindow` that takes strings `s` and `t` as parameters.
   * Let `l` and `r` represent the left and right boundaries of the sliding window.

2. **Initialize variables**
   * `cnt = 0` → keeps track of the number of characters from `t` currently matched in the window.
   * `minlen = INT_MAX` → stores the length of the minimum valid window found so far.
   * `sIndex = -1` → stores the starting index of the minimum valid window.
   * Create `vector<int> hash(256, 0)` to store the frequency of each character required from `t`.

3. **Handle the invalid case**
   * If `t.length() > s.length()`, return an empty string.

4. **Store character frequencies**
   * Iterate through `t` and increment the corresponding frequency in `hash`.

5. **Expand the sliding window**
   * Move the `r` pointer from left to right through `s`.
   * If `hash[s[r]] > 0`, the current character is still required by `t`, so increment `cnt`.
   * Decrement `hash[s[r]]` to indicate that the character has been included in the current window.

6. **Check for a valid window**
   * Whenever `cnt == t.length()`, the current window contains all characters of `t` with the required frequencies.
   * Compare the current window length `r - l + 1` with `minlen`.
   * If it is smaller:
     * Update `minlen`.
     * Store the current `l` in `sIndex`.

7. **Shrink the window**
   * Try to minimize the valid window by moving `l` to the right.
   * Before moving `l`, increment `hash[s[l]]`.
   * If `hash[s[l]] > 0`, removing `s[l]` causes the window to lose a required character, so decrement `cnt`.
   * Continue shrinking while `cnt == t.length()`.

8. **Continue the process**
   * Keep expanding and shrinking the sliding window until `r` reaches the end of `s`.

9. **Return the result**
   * If `sIndex == -1`, no valid window exists, so return `""`.
   * Otherwise, return:

   ```cpp
   s.substr(sIndex, minlen);
   ```

### Key Idea

The `hash` array represents the **remaining character requirements** of `t`.
As the right pointer expands, required characters decrease the corresponding frequency. As the left pointer shrinks the window, those frequencies are restored. This allows the algorithm to efficiently find the smallest window containing all characters of `t`.


COMPLEXITY ANALYSIS:
- Time complexity: O(2N), where m is the length of 's' and n is the length of 't'. We iterate over both strings once using the sliding window approach.
- Space complexity: O(1), as the space used by the unordered_map is proportional to the number of unique characters in 't', which can be at most 'n'.
*/

// code
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l = 0, r = 0, cnt = 0;
        int n = s.size(), m = t.size();
        int sIndex = -1, minlen = INT_MAX;
        vector<int> hash(256, 0);
        if (m > n)
            return "";
        for (int i = 0; i < m; i++)
        {
            hash[t[i]]++;
        }
        while (r < n)
        {
            if (hash[s[r]] > 0)
            {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == m)
            {
                if ((r - l + 1) < minlen)
                {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};