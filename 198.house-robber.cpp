/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return maxRobMemo(nums, dp, n-1);
    }

    int maxRob(vector<int>& nums, vector<int>& dp, int index) {
        if (index < 0) { return 0; }
        if (dp[index] != -1) { return dp[index]; }

        dp[index] = max(maxRob(nums, dp, index-1),
                        maxRob(nums, dp, index-2) + nums[index]);

        return dp[index];
    }

    int maxRobMemo(vector<int>& nums, vector<int>& dp, int index) {
        if (nums.size() == 1) { return nums[0]; }
        if (nums.size() == 2) { return max(nums[0], nums[1]); }

        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for (int i=2; i<=index; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[index];
    }
};
// @lc code=end

