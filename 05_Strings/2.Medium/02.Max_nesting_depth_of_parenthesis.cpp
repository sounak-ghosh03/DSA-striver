/*
Question: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
Given a VPS represented as a string s, return the nesting depth of s.

Approach:
1. Initialize `opened` as 0 and `ans` as 0 to keep track of the number of opened parentheses and the maximum nesting depth respectively.
2. Iterate through each character `c` in the string `s`.
    a. If `c` is an opening parenthesis '(', increment `opened` by 1 and update `ans` if it is greater than the current value of `ans`.
    b. If `c` is a closing parenthesis ')', decrement `opened` by 1.
3. Return `ans` as the maximum nesting depth.

CODE:-

*/
#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int c = 0, ans = 0;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '(')
        {
            c++;
        }
        else if (s[i] == ')')
        {
            c--;
        }
        ans = max(c, ans);
    }
    return ans;
}

;
/*
Time Complexity: O(n), where n is the length of the string `s`.
Space Complexity: O(1)
*/