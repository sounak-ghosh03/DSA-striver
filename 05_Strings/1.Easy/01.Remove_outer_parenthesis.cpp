/*
Question:https://leetcode.com/problems/remove-outermost-parentheses/description/
Given a valid parentheses string `s`, remove the outermost parentheses of every primitive string in the primitive decomposition of `s`.

Approach:
- We can iterate through the characters of the string and keep track of the number of open parentheses encountered.
- Whenever we encounter an opening parenthesis, if the count of open parentheses is greater than 0, we append it to the result string.
- When we encounter a closing parenthesis, we decrement the count of open parentheses and append it to the result string only if the count is greater than 1.

Code:
*/
#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s)
{
    string ans;
    int count = 0;
    for (auto c : s)
    {
        if (c == '(')
        {
            if (count > 0)
            {
                ans += c;
            }
            count++;
        }
        else
        {
            if (count > 1)
            {
                ans += c;
            }
            count--;
        }
    }
    return ans;
}
/*
Time Complexity: O(N), where N is the length of the input string `s`.
Space Complexity: O(N), where N is the length of the input string `s`.
*/