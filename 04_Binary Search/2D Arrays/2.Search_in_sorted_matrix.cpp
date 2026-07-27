/*
QUESTION:- https://leetcode.com/problems/search-a-2d-matrix/description/
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:
Input:  matrix = [[1,3,5,7]
                [10,11,16,20]
                [23,30,34,60]]
        target = 3
Output: true
*/

// brute
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// better:

int bs(vector<int> &nums, int target)
{
    int left = 0, high = nums.size() - 1;

    while (left <= high)
    {
        int mid = left + (high - left) / 2;

        if (nums[mid] == target)
            return true;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1])
        {
            if (bs(matrix[i], target))
            {
                return true;
            }
        }
    }
    return false;
}

/*
Optimal APPROACH:-
-> Since the array is sorted we can use binary search low = 0 and high = n*m-1 i.e. total number of elements
-> Value at mid position could be accessed by matrix[mid/m][mid%m]
-> Then, follow the traditional binary search
*/

// CODE:-
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

// TIME COMPLEXITY = O(log(M * N))
// SPACE COMPLEXITY = O(0)

// optimal: BS
