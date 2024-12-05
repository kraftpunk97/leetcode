/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(1001, -1);
        int min_cost = costUtil(dp, cost, n);
        return min_cost;
    }

    int costUtil(vector<int>& dp, vector<int>& cost, int index) {
        if (dp[index] != -1) { return dp[index]; }
        if (index < 0) { return INT_MAX; }
        if (index==0 || index==1) { return 0; }

        dp[index] = min(costUtil(dp, cost, index-1) + cost[index-1], 
                        costUtil(dp, cost, index-2) + cost[index-2]);
        return dp[index];
    }

    int costUtilMemo(vector<int>& dp, vector<int>& cost, int index) {
        dp[0] = 0;
        dp[1] = 0;
        for (int i=2; i<=index; i++) {
            dp[i] = min(dp[i-2] + cost[i-2],
                        dp[i-1] + cost[i-1]);
        }
        return dp[index];
    }
};
// @lc code=end

int main(int argv, char* argc[]) {
    
    return 0;
}