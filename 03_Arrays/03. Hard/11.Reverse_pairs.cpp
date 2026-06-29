/*
QUESTION: https://leetcode.com/problems/reverse-pairs/description/
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
*/

// brute
#include <bits/stdc++.h>
using namespace std;

int team(vector<int> &skill, int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (skill[i] > 2 * skill[j])
                cnt++;
        }
    }
    return cnt;
}

/*
APPROACH:
To solve this problem, we can use the merge sort algorithm. While merging the two sorted subarrays, we can count the number of reverse pairs.

1. Define a variable 'rev_pair' to store the count of reverse pairs.
2. Implement the 'merge' function to merge two subarrays and count the reverse pairs.
3. Implement the 'mergesort' function to recursively divide the array into subarrays and perform merge sort.
4. Initialize 'rev_pair' to 0 and call the 'mergesort' function on the given array.
5. Return the 'rev_pair' as the result.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;
int rev_pair = 0;

void merge(int start, int mid, int end, vector<int> &nums)
{
    int left_size = mid - start + 1;
    int right_size = end - mid;
    vector<int> left(left_size);
    vector<int> right(right_size);

    for (int i = 0; i < left_size; i++)
    {
        left[i] = nums[start + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right[i] = nums[mid + 1 + i];
    }

    // main logic resides here
    int m = 0;
    for (int i = 0; i < left_size; i++)
    {
        while (m < right_size && left[i] > (long long)2 * right[m])
        {
            m++;
        }
        rev_pair += m;
    }

    int i = 0, j = 0, k = start;
    while (i < left_size && j < right_size)
    {
        if (left[i] > right[j])
        {
            nums[k++] = right[j++];
        }
        else
        {
            nums[k++] = left[i++];
        }
    }
    while (i < left_size)
    {
        nums[k++] = left[i++];
    }
    while (j < right_size)
    {
        nums[k++] = right[j++];
    }
}

void mergesort(int start, int end, vector<int> &nums)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergesort(start, mid, nums);
    mergesort(mid + 1, end, nums);
    merge(start, mid, end, nums);
}

int reversePairs(vector<int> &nums)
{

    mergesort(0, nums.size() - 1, nums);
}

// TIME COMPLEXITY: O(n log n), where n is the size of the array.
// SPACE COMPLEXITY: O(n), where n is the size of the array.

/*
Here's an approach that matches the given code exactly:

### **Approach:**

We use the **Merge Sort** algorithm because it divides the array into sorted halves, allowing us to efficiently count reverse pairs during the merge process.

1. **Recursively divide the array** into two halves using the `mergeSort` function until each subarray contains a single element.
2. **Count reverse pairs before merging** the two sorted halves:

   * For every element in the left half, use a pointer in the right half to count elements satisfying the condition `arr[i] > 2 * arr[right]`.
   * Since both halves are already sorted, the right pointer only moves forward, making the counting process linear.
   3. **Merge the two sorted halves** into a temporary array using the `merge` function and copy the merged elements back to the original array.
   4. **Accumulate the counts** obtained from:

   * the left half,
   * the right half, and
   * the reverse pairs across the two halves.
   5. The final count returned by `mergeSort` is the total number of reverse pairs in the array.

This approach runs in **O(N log N)** time, as counting and merging each level of recursion takes **O(N)** and there are **O(log N)** levels.
   */

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;

    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high); // merging sorted halves
    return cnt;
}
