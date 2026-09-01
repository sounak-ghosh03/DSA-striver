/*
Question: https://leetcode.com/problems/sort-characters-by-frequency/description/
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.

Your approach doesn’t match the given code in two important ways:

* The code uses a **frequency map + vector + sorting**, not a priority queue.
* The code sorts the vector of `(character, frequency)` pairs in **decreasing order of frequency**.

Approach

1. Create a frequency map to count the occurrences of each character in the string.
2. Store the map entries in a vector as `(character, frequency)` pairs.
3. Sort the vector in decreasing order of frequency using a custom comparator.
4. Traverse the sorted vector and append each character to the answer string as many times as its frequency.
5. Return the resulting string, where characters with higher frequencies appear first.
*/

#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    map<char, int> freq;

    // Count frequency of each character
    for (char c : s)
    {
        freq[c]++;
    }

    // Store (character, frequency) pairs in a vector
    vector<pair<char, int>> arr;
    for (auto p : freq)
    {
        arr.push_back(p);
    }

    // Sort characters by frequency in decreasing order
    sort(arr.begin(), arr.end(),
         [](auto &a, auto &b)
         {
             return a.second > b.second;
         });

    // Build the answer according to frequencies
    string ans;
    for (auto p : arr)
    {
        ans.append(p.second, p.first);
    }

    return ans;
}

/*
Time complexity: O(n + k log k), where `n` is the length of the string and `k` is the number of distinct characters.
Space complexity: O(k) for the frequency map, vector, and result.
*/
