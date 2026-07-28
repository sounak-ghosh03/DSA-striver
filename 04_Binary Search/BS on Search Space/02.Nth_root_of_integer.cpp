/*
QUESTION:
You are given 2 numbers (n, m); the task is to find n√m (nth root of m).

Example:

Input: n = 2, m = 9
Output: 3
Explanation: 3^2 = 9

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not an integer.

APPROACH:
We can use a binary search algorithm to find the nth root of m.
1. Initialize the search range with low = 1 and high = m.
2. While low is less than or equal to high:
   - Calculate the mid value as the average of low and high.
   - If mid raised to the power of n is equal to m, return mid.
   - If mid raised to the power of n is less than m, update low to mid + 1.
   - If mid raised to the power of n is greater than m, update high to mid - 1.
3. If the loop exits without finding the nth root, return -1.


CODE:
*/
#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (pow(mid, n) == m)
            return mid;
        else if (pow(mid, n) < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// another approach

// return 1 if ==m
// return 0 if <m
// return 2 if > m

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

/*
TIME COMPLEXITY: O(log m)
The binary search algorithm runs in logarithmic time complexity as it reduces the search range by half at each step.

SPACE COMPLEXITY: O(1)
The algorithm uses a constant amount of space to store the variables and perform calculations.
*/