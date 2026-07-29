/*
Question: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
You are given an integer array bloomDay, an integer m, and an integer k. You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, where the i-th flower will bloom on the bloomDay[i] day and can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets, return -1.

Example:

Input:
bloomDay = [1,10,3,10,2]
m = 3
k = 1

Output:
3

Explanation:
Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
*/

/*
Approach:

* First, check whether it is possible to make `m` bouquets of size `k`. If `m * k` is greater than the total number of flowers, return `-1` since there are not enough flowers.

* Find the minimum and maximum bloom days in the `bloomDay` array. These values define the search space for binary search.

* Apply binary search on the range `[minimum bloom day, maximum bloom day]`:
  * Calculate the middle day (`mid`).
  * Check whether it is possible to make at least `m` bouquets by day `mid`.

* To check feasibility for a given day:
  * Traverse the `bloomDay` array and count consecutive flowers that have bloomed (`bloomDay[i] <= day`).
  * If a flower has not bloomed (`bloomDay[i] > day`), calculate the number of bouquets that can be formed from the current consecutive segment using `cnt / k`, add it to the total bouquet count, and reset the consecutive flower count.
  * After completing the traversal, process the last consecutive segment in the same way.
  * If the total number of bouquets formed is at least `m`, then the current day is feasible.

* During binary search:
  * If the current day is feasible, store it as the current answer and continue searching in the left half to find a smaller valid day.
  * Otherwise, search in the right half since more days are required for enough flowers to bloom.

* Return the minimum day that allows making at least `m` bouquets.

*/
#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int cnt = 0, boq = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
            cnt++;
        else
        {
            boq += (cnt / k);
            cnt = 0;
        }
    }
    boq += (cnt / k);
    if (boq >= m)
        return true;

    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    long long val = m * 1LL * k * 1LL;
    int n = bloomDay.size();

    if (val > n)
        return -1;
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        low = min(low, bloomDay[i]);
        high = max(high, bloomDay[i]);
    }
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(bloomDay, mid, m, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
// Time Complexity: The binary search approach takes O(log n), where n is the number of elements in the `bloomDay` array.
// Space Complexity: The space complexity is O(1) since we are using a constant amount of extra space.