/*
QUESTION: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
Given a string s consisting only of characters 'a', 'b', and 'c', you need to count the number of substrings that contain at least one occurrence of all these characters.
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
*/
// bruteforce solution:
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> hash(3, 0);
            for (int j = i; j < n; j++)
            {
                hash[s[j] - 'a'] = 1;
                if (hash[0] + hash[1] + hash[2] == 3)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
/*
APPROACH:
To count the number of substrings containing at least one occurrence of `'a'`, `'b'`, and `'c'`, we can use the last-seen index technique.

1. Create an array `lastSeen[3]` to store the most recent index of each character:

   * `lastSeen[0]` → last position of `'a'`
   * `lastSeen[1]` → last position of `'b'`
   * `lastSeen[2]` → last position of `'c'`

   Initialize all three values to `-1`, indicating that the characters have not appeared yet.

2. Initialize:

   * `cnt` → number of valid substrings.
   * `n` → length of the string.

3. Iterate through the string using index `i`:

   * Update the last-seen position of the current character using:
     `lastSeen[s[i] - 'a'] = i`.

4. Check whether all three characters have appeared:

   * If any value in `lastSeen` is still `-1`, a valid substring cannot yet be formed.
   * Otherwise, all three characters `'a'`, `'b'`, and `'c'` are present in the prefix ending at `i`.

5. When all three characters have appeared, find the minimum of their last-seen positions:
   `min({lastSeen[0], lastSeen[1], lastSeen[2]})`.

   Let this minimum position be `m`.

   * Any starting index from `0` to `m` will produce a substring ending at `i` that contains all three characters.
   * Therefore, there are `m + 1` valid substrings ending at index `i`.

6. Add `1 + min({lastSeen[0], lastSeen[1], lastSeen[2]})` to `cnt`.

7. After processing the entire string, return `cnt`, which represents the total number of substrings containing at least one `'a'`, `'b'`, and `'c'`.

*/

// optimal
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int lastSeen[3] = {-1, -1, -1};
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
        return cnt;
    }
};

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(n), where n is the length of the string s. We iterate over the string once.
- Space complexity: O(1), as the extra space used is constant throughout the algorithm.
*/
