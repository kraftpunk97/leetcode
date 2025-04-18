/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //return twoPointers(prices);
        return DP(prices);
    }

    int twoPointers(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
        {
            return 0;
        }

        int L = 0;
        int R = 1;
        int maxProfit = 0;
        while (L <= R && R < n)
        {
            int runningProfit = prices[R] - prices[L];
            maxProfit = max(maxProfit, runningProfit);
            if (runningProfit < 0)
            {
                L += 1;
            }
            else
            {
                R += 1;
            }
        }
        return maxProfit;
    }

    int DP(vector<int> &prices)
    {
        int minBuy = prices[0];
        int maxProfit = 0;

        for (auto sell: prices)
        {
            maxProfit = max(maxProfit, sell-minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxProfit;
    }
};
// @lc code=end
