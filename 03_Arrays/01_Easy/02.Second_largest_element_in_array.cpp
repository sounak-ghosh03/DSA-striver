/*
QUESTION:-
Given an array Arr of size N, print second largest distinct element from an array.

Example:

Input:
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the
array is 35 and the second largest element
is 34.
*/

/*
APPROACH
BRUTE FORCE:
--> Sort the array
--> Return the second last element after checking for duplicates

TIME COMPLEXITY = O(NlogN + N)
SPACE COMPLEXITY = O(0)

OPTIMAL:
-> Initialize two variables large with a[0] and second_large with -1
-> Traverse the array and if the current element is larger than ‘large’ then update it for large and second_large variables 
-> Else if the current element is larger than ‘second_large’ and not equal to large then we update the variable second_large.
-> Once we traverse the entire array, we would find the second largest element in the variable second_large.

TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(0)
*/

// CODE:-
int print2largest(int arr[], int n)
{
    int slarge = -1, large = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > large)
        {
            slarge = large;
            large = arr[i];
        }
        else if (arr[i] > slarge && arr[i] != large)
            slarge = arr[i];
    }
    return slarge;
}
