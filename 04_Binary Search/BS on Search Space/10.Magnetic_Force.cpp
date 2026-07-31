/*
Question: https://leetcode.com/problems/magnetic-force-between-two-balls/
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

Example:

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Approach:

* Sort the `position` array in ascending order so that the balls can be placed greedily.
* Apply binary search on the minimum magnetic force (distance) between any two balls.
* Initialize:

  * `low = 0` (minimum possible distance as used in the code).
  * `high = position[n-1] - position[0]` (maximum possible distance).
* While `low <= high`:

  * Compute `mid` as the candidate minimum magnetic force.
  * Use the `canPlace()` function to check whether it is possible to place at least `m` balls such that the minimum distance between any two placed balls is at least `mid`.

    * Place the first ball at the first position.
    * Traverse the sorted array and place the next ball whenever the distance from the last placed ball is at least `mid`.
    * If the number of placed balls is at least `m`, return `true`; otherwise, return `false`.
  * If `canPlace()` returns `true`, store `mid` as the current answer and search for a larger minimum distance by setting `low = mid + 1`.
  * Otherwise, search for a smaller distance by setting `high = mid - 1`.
* After the binary search completes, return the maximum possible minimum magnetic force stored in `ans`.

Code:
*/
#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &position, int dist, int m)
{
    int cntBalls = 1, last = position[0];
    for (int i = 0; i < position.size(); i++)
    {
        if (position[i] - last >= dist)
        {
            cntBalls++;
            last = position[i];
        }
    }
    if (cntBalls >= m)
        return true;
    else
        return false;
}
int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());
    int n = position.size(), ans = 0;
    int low = 0, high = position[n - 1] - position[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPlace(position, mid, m))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

/*
Time Complexity: O(n log n), where n is the size of the position array. Sorting the array takes O(n log n) time and the binary search takes O(log n) time.
Space Complexity: O(1), constant space is used.
*/
