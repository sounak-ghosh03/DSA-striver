/*
QUESTION: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1.
However, choosing the rightmost card first will maximize your total score.
The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.


APPROACH:

To maximize the score, we can choose exactly `k` cards from either the left end or the right end of the array.
Therefore, we can try all possible combinations of taking some cards from the left and the remaining cards from the right.

1. Initialize `lsum`, `rsum`, and `maxsum` to `0`. Let `n` be the size of `cardPoints`.

2. First, take all `k` cards from the **left side**:
   - Add the first `k` elements to `lsum`.
   - Initialize `maxsum` with this value.
   - Set `rightIndex` to `n - 1`, pointing to the last card.

3. Now gradually replace cards taken from the left with cards taken from the right:
   - Iterate from `i = k - 1` down to `0`.
   - Remove `cardPoints[i]` from `lsum`.
   - Add `cardPoints[rightIndex]` to `rsum`.
   - Decrease `rightIndex`.
   - Update `maxsum` with `lsum + rsum`.

4. This considers all possible combinations:
   - `k` cards from the left and `0` from the right.
   - `k-1` cards from the left and `1` from the right.
   - `k-2` cards from the left and `2` from the right.
   - `0` cards from the left and `k` from the right.

5. Return `maxsum` as the maximum score.

Complexity Analysis:
Time complexity: `O(k)`, because we iterate through the first `k` cards once and then perform another loop of `k` iterations.
Space complexity: `O(1)`, because only a constant number of variables are used.

**Note:** This approach is different from the `totalSum - minimum subarray sum` approach, although both have `O(n)`-type overall performance when `k` can be proportional to `n`. Your **given code specifically implements the left-right two-pointer approach**, so the above explanation matches it directly.

*/

// code
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int lsum = 0, rsum = 0, maxsum = 0;
        int n = cardPoints.size();
        int rightIndex = 0;
        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
            maxsum = lsum;
            rightIndex = n - 1;
        }
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndex];
            rightIndex--;
            maxsum = max(maxsum, (lsum + rsum));
        }
        return maxsum;
    }
};