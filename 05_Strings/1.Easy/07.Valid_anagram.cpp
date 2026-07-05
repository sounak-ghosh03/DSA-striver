/*
QUESTION:- https://leetcode.com/problems/valid-anagram/description/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Approach:
1. Check if the lengths of strings `s` and `t` are different. If they are, return `false` since anagrams must have the same number of characters.
2. Sort both strings `s` and `t` in lexicographical order.
3. Compare the sorted strings.
4. If both sorted strings are identical, return `true`; otherwise, return `false`.


Code:
*/
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(log n) or O(1)
*/
