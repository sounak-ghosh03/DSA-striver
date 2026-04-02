/*
I don't think anyone needs it's solution. 
The idea is to traverse the array using loop and when the element is equal to k return the same
*/

// CODE:-
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}