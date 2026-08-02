/*QUESTION: https://leetcode.com/problems/median-of-two-sorted-arrays/
Given two sorted arrays nums1 and nums2 of sizes m and n respectively, you need to find the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


*/
// brute force
#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    vector<int> arr3;
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr3.push_back(a[i++]);
        }
        else
        {
            arr3.push_back(b[j++]);
        }
    }

    while (i < n1)
        arr3.push_back(a[i++]);
    while (j < n2)
        arr3.push_back(b[j++]);

    int n = n1 + n2;

    if (n % 2 == 1)
    {
        return arr3[n / 2];
    }

    return (double)(arr3[n / 2] + arr3[n / 2 - 1]) / 2.0;
}

/*
APPROACH:


To find the median of two sorted arrays in **O(log(min(m, n)))** time, we use **binary search** on the smaller array to determine the correct partition.

1. Let `n1` and `n2` be the sizes of `nums1` and `nums2`.
2. Always perform binary search on the smaller array. If `nums1` is larger than `nums2`, swap the arrays by recursively calling the function with reversed arguments.
3. Compute:

   * `n = n1 + n2`, the total number of elements.
   * `left = (n1 + n2 + 1) / 2`, which represents the number of elements that should be present in the left half after partitioning.
4. Initialize the binary search range:

   * `low = 0`
   * `high = n1`
5. Perform binary search while `low <= high`:

   * Compute the partition indices:

     * `mid1 = (low + high) / 2`, the partition position in `nums1`.
     * `mid2 = left - mid1`, the corresponding partition position in `nums2`.
   * Determine the elements around the partitions:

     * `l1` = element just left of the partition in `nums1` (or `INT_MIN` if no such element).
     * `r1` = element just right of the partition in `nums1` (or `INT_MAX` if no such element).
     * `l2` = element just left of the partition in `nums2` (or `INT_MIN` if no such element).
     * `r2` = element just right of the partition in `nums2` (or `INT_MAX` if no such element).
   * If `l1 <= r2` and `l2 <= r1`, the correct partition has been found:

     * If the total number of elements is odd, the median is `max(l1, l2)`.
     * Otherwise, the median is the average of `max(l1, l2)` and `min(r1, r2)`.
   * If `l1 > r2`, move the partition in `nums1` to the left by setting `high = mid1 - 1`.
   * Otherwise, move the partition to the right by setting `low = mid1 + 1`.
6. If no valid partition is found (which should not occur for valid sorted input), return `0.0`.


CODE:*/

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);
    int low = 0, high = n1, left = (n1 + n2 + 1) / 2;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = (left - mid1);
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0.0;
}

/*
identify the samller of the two arrays and then perform the bonary search on the smaller array
COMPLEXITY ANALYSIS:
- Time complexity: O(log(min(m, n))), where m and n are the sizes of the input arrays nums1 and nums2, respectively. We perform binary search on the smaller array.
- Space complexity: O(1), as we use constant extra space throughout the algorithm.
*/
