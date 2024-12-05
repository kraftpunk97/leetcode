/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX); // For bottom up
        //unordered_map<int, int> dp; // For top down


        int fewestCoins = BottomUp(coins, dp, amount);
        return fewestCoins==INT_MAX ? -1 : fewestCoins;
    }

    int BottomUp(vector<int>& coins, vector<int>& dp, int amount) {
        //sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int value=0; value<=amount; value++) {
            for (int coin: coins) {
                if (value>=coin && dp[value-coin]!=INT_MAX) {
                    dp[value] = min(dp[value], dp[value-coin]+1);
                }
            }
        }
        return dp[amount];
    }

    int TopDown(vector<int>& coins, unordered_map<int, int>& dp, int amount) {
        if (amount == 0) { return 0; }
        if (dp.find(amount) != dp.end()) { return dp[amount]; }

        int fewestCoins = INT_MAX;
        for (int denomination: coins) {
            int remaining_amount = amount - denomination;
            if (remaining_amount >= 0) {
                int remaining_coins = TopDown (coins, dp, remaining_amount);
                if (remaining_coins!=INT_MAX) {
                    fewestCoins = min(fewestCoins, remaining_coins + 1);
                }
            }
        }
        dp[amount] = fewestCoins;
        return dp[amount];
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> coins = vector<int>({1,2,5});
    cout << s.coinChange(coins, 11);
    return 0;
}