/*
QUESTION:-
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

/*
APPROACH:-
BRUTE FORCE:-
--> Traverse the array and check if the current element is zero or not
--> Store the non-zero elements in a temp array
--> Replace the current element with zero
--> Copy the temp array into the original array

for (int i = 0; i < nums.size(); i++)
{
    if(arr[i]!=0){
        temp.push_back(arr[i]);
        arr[i]=0;
    }
}
->> Time complexity = O(N)
->> Space complexity = O(N)


OPTIMAL:-
--> Store the index of the current non-zero element
--> Traverse the array and check if the current element is zero or not
--> Swap the current non-zero element with the element at j
--> Increment j

--> Time complexity = O(N)
--> Space complexity = O(1)
*/

// CODE:-
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
