/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cheapest_price = prices[0];
        int max_profit = 0;
        for (int i=1; i<n; i++) {
            int profit = prices[i] - cheapest_price;
            max_profit = max(profit, max_profit);
            if (prices[i] < cheapest_price) {
                cheapest_price = prices[i];
            }
        }
        return max_profit;
    }
};
// @lc code=end

