/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        bool buying = true;         
        return TopDown(prices, dp, true, 0);
    }

    int TopDown(vector<int>& prices, vector<vector<int>>& dp, bool buying, int day) {
        if (day >= prices.size()) { return 0; }

        if (dp[day][buying] != -1) { return dp[day][buying]; }

        int cooldown = TopDown(prices, dp, buying, day+1); // We always have the option of not doing anything
        if (buying) {
            int buy = TopDown(prices, dp, false, day+1) - prices[day]; // If you are buying today, you can't buy tomorrow
            dp[day][buying] = max(buy, cooldown);
        } else {
            int sell = TopDown(prices, dp, true, day+2) + prices[day];  // If you are selling today, you can only buy two days from now.
            dp[day][buying] = max(sell, cooldown);
        }
        return dp[day][buying];
    }
};
// @lc code=end

