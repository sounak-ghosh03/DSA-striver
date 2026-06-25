/*
QUESTION: https://leetcode.com/problems/merge-sorted-array/description/
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

*/
// brute
#include <bits/stdc++.h>
using namespace std;
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{

    int n = a.size();
    int m = b.size();

    long long c[n + m];
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m)
    {
        if (a[left] <= b[right])
        {
            c[index] = a[left];
            left++, index++;
        }
        else
        {
            c[index] = b[right];
            right++, index++;
        }
    }

    while (left < n)
    {
        c[index++] = a[left++];
    }
    while (right < m)
    {
        c[index++] = b[right++];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            a[i] = c[i];
        else
            b[i - n] = c[i];
    }
}

/*
OPTIMAL APPROACH:
To merge two sorted arrays, nums1 and nums2, into nums1, we use a three-pointer approach starting from the end of the arrays. This avoids overwriting the valid elements already present in nums1.

- Initialize three pointers:
  - i points to the last valid element in nums1 (m - 1).
  - j points to the last element in nums2 (n - 1).
  - k points to the last position of nums1 (m + n - 1), where the next largest element should be placed.
- Compare the elements at nums1[i] and nums2[j].
- If nums1[i] is greater, place it at nums1[k], then decrement both i and k.
- Otherwise, place nums2[j] at nums1[k], then decrement both j and k.
- Repeat steps 2–4 until one of the arrays has been completely processed.
- If there are any elements remaining in nums2, copy them into the remaining positions of nums1. Any remaining elements in nums1 are already in their correct positions, so no additional work is needed.
f there are any elements remaining in nums2, copy them into the remaining positions of nums1. Any remaining elements in nums1 are already in their correct positions, so no additional work is needed.

CODE:
*/
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    while (j >= 0)
        nums1[k--] = nums2[j--];
}

// Time Complexity: O(m + n)
// Space Complexity: O(1)


// optimal 2 : gap method

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = gap;

        while (right < len)
        {
            if (left < n && right < n)
            {
                // both pointer in array 'a'
                if (a[left] > a[right])
                    swap(a[left], a[right]);
            }
            else if (left < n && right >= n)
            {
                // pointer in 'a' and 'b'
                if (a[left] > b[right - n])
                    swap(a[left], b[right - n]);
            }
            else
            {
                // both pointers in array 'b'
                if (b[left - n] > b[right - n])
                    swap(b[left - n], b[right - n]);
            }

            left++;
            right++;
        }

        if (gap == 1)
            gap = 0;
        else
            gap = (gap / 2) + (gap % 2);
    }
}
/*
TIME COMPLEXITY: O(m + n), where m and n are the lengths of nums1 and nums2 respectively.
The merging process requires iterating through both arrays once.
SPACE COMPLEXITY: O(1)
The merge is performed in-place without using any additional space.

*/
