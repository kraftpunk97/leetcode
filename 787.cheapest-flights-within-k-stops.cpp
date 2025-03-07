/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return bellmanFord(n, flights, src, dst, k);
    }

    int bellmanFord(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prev_costs(n, INT_MAX);
        vector<int> curr_costs;
        prev_costs[src] = 0;

        for (int i=0; i<k+1; i++) {
            curr_costs = prev_costs;
            bool updated = false;
            for (auto flight: flights) {
                int from = flight[0], to = flight[1], cost_from_to = flight[2];
                if (prev_costs[from]!=INT_MAX) {
                    curr_costs[to] = min(curr_costs[to], prev_costs[from]+cost_from_to);
                }
            }
            prev_costs = curr_costs;
        }
        return prev_costs[dst]==INT_MAX ? -1 : prev_costs[dst];
    }
};
// @lc code=end

