/*
QUESTION: https://leetcode.com/problems/find-a-peak-element-ii/description/
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

APPROACH:

* Perform a binary search on the columns of the matrix.
* For the current middle column, find the row containing the maximum element in that column.
* Compare this maximum element with its immediate left and right neighbors (if they exist).
* If the current element is greater than both neighbors, it is a peak element, so return its coordinates.
* If the left neighbor is greater, then a peak must exist on the left half, so continue the binary search on the left.
* Otherwise, continue the binary search on the right half.
* If no peak is found (though the problem guarantees one exists), return `{-1, -1}`.

CODE:
*/

#include <bits/stdc++.h>

using namespace std;

int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxVal = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxVal)
        {
            maxVal = mat[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int maxRowIndex = findMaxIndex(mat, n, m, mid);

        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;

        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}

/*
TIME COMPLEXITY: O(m log(n)) or O(n log(m)) - Binary search is performed on the columns of the matrix.
SPACE COMPLEXITY: O(1) - Constant space is used.
*/