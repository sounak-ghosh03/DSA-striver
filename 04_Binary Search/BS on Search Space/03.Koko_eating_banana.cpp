/*
QUESTION: https://leetcode.com/problems/koko-eating-bananas/description/
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

EXAMPLES:
Input: piles = [3,6,7,11], h = 8
Output: 4

Input: piles = [30,11,23,4,20], h = 5
Output: 30

APPROACH:
 optimal: BINARY SEARCH

* The minimum possible eating speed is **1 banana/hour**, and the maximum possible eating speed is the **largest pile of bananas**.
* First, find the maximum element in the `piles` array. This becomes the upper bound of the binary search.
* Apply **binary search** on the range **[1, maximum pile]** to find the minimum valid eating speed.
* For each middle value (`mid`), treat it as Koko's eating speed and calculate the **total hours required** to eat all the banana piles.
* The required hours for each pile are calculated as **`ceil(pile / mid)`**, since even if some bananas remain after eating for an hour, Koko needs another full hour to finish that pile.
* Sum the required hours for all piles:

  * If the total hours are **less than or equal to `h`**, then the current eating speed is sufficient. Store it as a possible answer and search for a smaller valid speed by moving to the left half.
  * Otherwise, the eating speed is too slow, so search in the right half by increasing the speed.
* Continue the binary search until the search space is exhausted.
* The stored answer represents the **minimum eating speed** required to finish all the bananas within `h` hours.



CODE:
*/
#include <bits/stdc++.h>
using namespace std;

// TO FIND MAXIMUM ELEMENT
int maxi(vector<int> &arr)
{
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > ans)
            ans = arr[i];
    }
    return ans;
}

// TO CALCULATE REQUIRED TIME
long long func(vector<int> &arr, int hourly)
{
    long long ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans += ceil((double)arr[i] / double(hourly));
    }
    return ans;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = maxi(piles), ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long totalHrs = func(piles, mid);
        if (totalHrs <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// TIME COMPLEXITY: O(N log M), where N is the number of piles and M is the maximum number of bananas in a pile.
// SPACE COMPLEXITY: O(1)