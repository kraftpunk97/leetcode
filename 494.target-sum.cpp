/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        /* // DFS Approach
        int combinations = 0;
        dfs(nums, target, n-1, combinations);
        return combinations;
        */

        // TopDown Apporach
        
        // BottomUp Appraoch
        return BottomUp(nums, target);

    }

    void dfs(vector<int>& nums, int res, int index, int& combinations) {
        int n = nums.size();
        if (index < 0) { return; }
        bool found_combinations = false;
        if (res-nums[index]==0 && index==0) { combinations++; }
        if (res+nums[index]==0 && index==0) { combinations++; }
        if (found_combinations) { return; }
        dfs(nums, res-nums[index], index-1, combinations);
        dfs(nums, res+nums[index], index-1, combinations);
    }



    int BottomUp(vector<int>& nums, int target) {
        int n = nums.size();
;        vector<unordered_map<int, int>> dp(n+1);
        dp[0][0] = 1;

        for (int i=0; i<n; i++) {
            for (auto& p: dp[i]) {
                dp[i+1][p.first + nums[i]] += p.second;
                dp[i+1][p.first - nums[i]] += p.second;
            }
        }

        return dp[n][target];
    }
};
// @lc code=end

