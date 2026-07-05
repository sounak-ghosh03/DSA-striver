/*
Question:https://leetcode.com/problems/reverse-words-in-a-string/description/

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example:
Input: s = "the sky is blue"
Output: "blue is sky the"

Approach:
* Initialize an empty string `result` to store the words in reversed order.
* Initialize an index `i` to point to the last character of the input string `s`.
* Traverse the string from right to left until `i` becomes negative.
* Skip all trailing or extra spaces by decrementing `i` while the current character is a space.
* If `i` becomes negative after skipping spaces, terminate the loop since all words have been processed.
* Store the current index in `end`, which marks the last character of the current word.
* Continue moving `i` left until a space or the beginning of the string is reached, thereby locating the start of the current word.
* Extract the current word using `s.substr(i + 1, end - i)` and store it in a temporary string `word`.
* If `result` is not empty, append a single space to separate the words.
* Append the extracted `word` to `result`.
* Repeat the above steps until all words have been processed.
* Return the final string `result`, which contains the words in reverse order with a single space between consecutive words.

Code:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int i = s.size() - 1;
        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }
            if (i < 0)
                break;
            int end = i;
            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }
            string word = s.substr(i + 1, end - i);

            if (!result.empty())
            {
                result += " ";
            }
            result += word;
        }
        return result;
    }
};

/*
Time Complexity: O(n), where n is the length of the input string 's'.
Space Complexity: O(n), where n is the length of the input string 's'.
*/
