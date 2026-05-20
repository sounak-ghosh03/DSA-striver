/*
QUESTION:- https://leetcode.com/problems/majority-element/
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

// brute force
#include <bits/stdc++.h>
using namespace std;
int majorityElement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                cnt++;
            }
            if (cnt > n / 2)
                return arr[i];
        }
    }
    return -1;
}

// better
#include <bits/stdc++.h>
using namespace std;
int majorityElementBetter(vector<int> arr)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (arr.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}
/*
OPTIMAL APROACH:-
-> Initialize two variables: candidate and count. Set candidate to the first element of the array, and count to 1.
-> Iterate through the array starting from the second element:
    If the current element is equal to the candidate, increment the count by 1.
    If the current element is different from the candidate, decrement the count by 1.
    If the count becomes 0, update the candidate to the current element and set the count to 1 again.
-> After the iteration, the candidate variable will hold the majority element.
Return the candidate as the result.
*/

// CODE:-
#include <bits/stdc++.h>
using namespace std;

int majorityElementOptimal(vector<int> arr)
{
    int cnt = 0;
    int el;

    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == el)
            cnt1++;
    }
    if (cnt1 > (arr.size() / 2))
    {
        return el;
    }
    return -1;
}

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)