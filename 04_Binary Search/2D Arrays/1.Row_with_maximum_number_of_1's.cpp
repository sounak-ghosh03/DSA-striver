/*
QUESTION:-
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input:
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).



APPROACH:

* Since each row of the matrix is sorted, all `0`s appear before `1`s.
* For every row, find the index of the **first occurrence of `1`** using **Lower Bound (Binary Search)**.
* If the first `1` is found at index `idx`, then the number of `1`s in that row is `m - idx`.
* Keep track of the maximum number of `1`s found so far and store the corresponding row index.
* After traversing all rows, return the index of the row having the maximum number of `1`s.
* If no `1` is present in the matrix, return `-1`.
*/

// CODE:-
#include <bits/stdc++.h>
using namespace std;

// lower bound code
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int max_ele = 0;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > max_ele)
        {
            max_ele = cnt_ones;
            index = i;
        }
    }
    return index;
}

// TIME COMPLEXITY = O(N Log M)
// SPACE COMPLEXITY = O(1)