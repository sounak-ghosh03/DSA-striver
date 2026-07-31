/*
Question: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Approach:
To find the minimum ship capacity required to deliver all packages within the given number of days, we use **binary search** on the answer.

* The **minimum possible capacity (`low`)** is the weight of the heaviest package, since the ship must be able to carry every package.
* The **maximum possible capacity (`high`)** is the sum of all package weights, which represents carrying all packages in a single day.

For each candidate capacity (`mid`), we determine the number of days required using the `requiredDay()` function:

* Start with `days = 1` and `load = 0`.
* Traverse the `weights` array:

  * If adding the current package exceeds the current capacity, increment the number of days and start a new day's load with the current package.
  * Otherwise, add the package to the current day's load.
* At the end of the traversal, return the total number of days required.

Using the returned number of days:

* If the required days are **less than or equal to** the given `days`, the current capacity is sufficient, so we try to find a smaller valid capacity by setting `high = mid - 1`.
* Otherwise, the capacity is too small, so we increase it by setting `low = mid + 1`.

The binary search continues until `low` exceeds `high`. At that point, `low` represents the **minimum ship capacity** required to ship all packages within the specified number of days.

Code:
*/
#include <bits/stdc++.h>
using namespace std;

int requiredDay(vector<int> &weights, int cap)
{
    int days = 1, load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i] + load > cap)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int numberOfDays = requiredDay(weights, mid);

        if (numberOfDays <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

/*
- Time Complexity: O(N log M), where N is the size of the weights array and M is the sum of all the weights.
- Space Complexity: O(1) as we are using a constant amount of extra space.
*/
