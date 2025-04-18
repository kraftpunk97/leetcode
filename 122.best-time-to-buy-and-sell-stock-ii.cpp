/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return linear(prices);
    }

    int linear(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
        {
            return 0;
        }

        if (n == 2)
        {
            return prices[0] < prices[1] ? prices[1] - prices[0] : 0;
        }

        int minBuy = prices[0];
        int profit = 0;

        for (int i = 1; i < n; i++)
        {
            if (prices[i - 1] >= prices[i])
            {
                profit += prices[i - 1] - minBuy;
                minBuy = prices[i];
            }
        }

        // What if the array ends with a buy?
        if (prices[n - 2] < prices[n - 1])
        {
            profit += prices[n - 1] - minBuy;
        }

        cout << profit << '\n';
        return profit;
    }

    int DP(vector<int> &prices)
    {
        int currHold = INT_MIN, currNotHold = 0;

        for (int stockPrice: prices)
        {
            int prevHold = currHold, prevNotHold = currNotHold;
            currHold = max(prevHold, prevNotHold - stockPrice);
            currNotHold = max(prevNotHold, prevHold + stockPrice);
        }
        return currNotHold;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> prices{1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9};
    s.maxProfit(prices);
    return 0;
}