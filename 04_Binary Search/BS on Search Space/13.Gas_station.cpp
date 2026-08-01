/*
Questions:-
We have an horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D. Find the answer exactly to 2 decimal places.

Example 1:

Input:
N = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
K = 9
Output: 0.50
Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
Example 2:

Input:
N = 10
stations = [3,6,12,19,33,44,67,72,89,95]
K = 2
Output: 14.00
Explanation: Construction of gas stations at 86 locations

Approach:
- To minimize the maximum distance between adjacent gas stations, we can perform binary search on the possible range of distances.
- Initialize `low` to 0 and `high` to the maximum distance between adjacent existing gas stations.
- While `high - low` is greater than a small threshold (e.g., 1e-6), calculate the mid-point `mid` between `low` and `high`.
- Check if it is possible to add `K` additional gas stations such that the maximum distance between adjacent gas stations is less than or equal to `mid`.
  - Iterate over the existing gas stations and check the distance between adjacent stations.
  - If the total number of additional stations required is less than or equal to `K`, it is possible to achieve the maximum distance `mid`.
- If it is possible, update `high` to `mid`, as we are looking for smaller distances.
- Otherwise, update `low` to `mid`.
- Finally, return the value of `low` plus a small value (e.g., 0.000001) to represent the answer to 2 decimal places.

Time Complexity: O(N log M), where N is the number of existing gas stations and M is the range of distances between adjacent gas stations.
Space Complexity: O(1), as we are using constant extra space.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(double mid, vector<int>& stations, int K) {
    int req_stations = 0;
    for (int i = 1; i < stations.size(); i++) {
        req_stations += floor((stations[i] - stations[i - 1]) / mid);
    }
    return req_stations <= K;
}

double findSmallestMaxDist(vector<int>& stations, int K) {
    double low = 0, high = stations[stations.size() - 1] - stations[0];
    while (high - low > 1e-6) {
        double mid = low + (high - low) / 2;
        if (isPossible(mid, stations, K)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low + 0.000001;
}


// better on using PQ

#include <bits/stdc++.h>

using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    // Push initial differences into the priority queue
    for (int i = 0; i < n - 1; i++)
    { // Corrected loop condition
        long double diff = arr[i + 1] - arr[i];
        pq.push({diff, i});
    }

    // Place gas stations
    for (int gasStations = 1; gasStations <= k; gasStations++)
    { // Corrected loop syntax
        auto tp = pq.top();
        pq.pop(); // Corrected the typo pq.top() -> pq.pop()
        int secIndex = tp.second;
        howMany[secIndex]++;
        long double iniDiff = arr[secIndex + 1] - arr[secIndex];
        long double newSecLen = iniDiff / (howMany[secIndex] + 1); // Corrected formula
        pq.push({newSecLen, secIndex});
    }

    return pq.top().first;
}


// Optimal: BS 

#include <bits/stdc++.h>

int numberOfGasstationReq(long double dist, vector<int> &arr) {
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        int numberInBetween = (arr[i] - arr[i - 1]) / dist;
        cnt += numberInBetween; 
    }
    return cnt;
}


long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff) {
        long double mid = low + (high - low) / 2.0;
        int cnt = numberOfGasstationReq(mid, arr);
        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}
