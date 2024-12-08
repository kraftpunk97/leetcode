/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        //vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        //int max_coins = TopDown(nums, dp, 1, n);
        int max_coins = BottomUp(nums);
        return max_coins;
    }

    int TopDown(vector<int>& nums, vector<vector<int>>& dp, int L, int R) {
        if (L > R) { return 0; }
        if (dp[L][R] != -1) { return dp[L][R]; }

        dp[L][R] = 0;
        for (int i=L; i<R+1; i++) {
            int coins = nums[L-1]*nums[i]*nums[R+1];
            coins += TopDown(nums, dp, L, i-1) + TopDown(nums, dp, i+1, R);
            dp[L][R] = max(coins, dp[L][R]);
        }
        return dp[L][R];
    }

    int BottomUp(vector<int>& nums) {
        /* 
        We basically look at the each possible subarray,
        For each subarray, we ask pick an element, and we ask,
        "What is the max coins, we can obtain with this subarray, if we remove the element we have picked last?"
        Removing an elem from the subarray, splits the subarray into two parts, the left and the right part.
        Which leads to two recursive calls for the two parts of the subarray.
        This is where the DP aspect of the problem kicks in.
        
        */
        int n = nums.size()-2; // `nums` already has the trailing 1's.
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int L=n; L>=1; L--) { // Left: n <-- 1
            for (int R=L; R<=n; R++) { // Right: Left --> n
                for (int i=L; i<=R; i++) { // i: Left --> Right
                    int coins = nums[L-1] * nums[i] * nums[R+1];
                    coins += dp[L][i-1] + dp[i+1][R];
                    dp[L][R] = max(dp[L][R], coins);
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

