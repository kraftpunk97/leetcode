/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
struct tuple<int, int, int> : public std::unary_function<tuple<int, int, int>, std::size_t>
{
   std::size_t operator()(const key_t& k) const
   {
      return get<0>(k)[0] ^ get<1>(k) ^ get<2>(k);
   }
};

struct key_equal : public std::binary_function<key_t, key_t, bool>
{
   bool operator()(const key_t& v0, const key_t& v1) const
   {
      return (
               std::get<0>(v0) == std::get<0>(v1) &&
               std::get<1>(v0) == std::get<1>(v1) &&
               std::get<2>(v0) == std::get<2>(v1)
             );
   }
};
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = DP(prices);
        //cout << res << '\n';
        return res;
    }

    int DP(vector<int> &prices)
    {
        int n = prices.size();
        unordered_map<tuple<int, int, int>, int, > dp;
        return DFS(0, 0, -1, 0, prices, dp);
    }

    int DFS(int idx, int currProfit, int buyIdx, int purchases, vector<int> &prices, unordered_map<tuple<int, int, int>, int> &dp)
    {
        auto tup = make_tuple(idx, buyIdx, purchases);
        if (idx == prices.size())
        {
            return currProfit;
        }
        if (dp[tup] != -1)
        {
            return dp[tup];
        }
        if (purchases == 2)
        {
            return currProfit;
        }

        // We have two choices
        // 1. Do nothing
        int doNothingProfit = DFS(idx + 1, currProfit, buyIdx, purchases, prices, dp);

        // 2. Flip the hold state (if holding, then sell. Otherwise buy)
        if (buyIdx == -1) // buyPrice is -1 when not holding.
        {
            buyIdx = idx;
        }
        else
        {
            currProfit += prices[idx] - prices[buyIdx];
            purchases += 1;
            buyIdx = -1;
        }
        int flipStateProfit = DFS(idx + 1, currProfit, buyIdx, purchases, prices, dp);
        dp[tup] = max(flipStateProfit, doNothingProfit);
        return dp[tup];
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> prices{1,2,4,2,5,7,2,4,9,0};
    s.maxProfit(prices);
    return 0;
}