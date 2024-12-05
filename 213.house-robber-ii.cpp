/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { return nums[0]; }

        vector<int> dp(n+1, -1);

        // The only new contraint compared to House Robber I,
        // is that you can not select both the first and the last house.
        // Solution is to run the dp algorithm on nums[0->n-2] and nums[1->n-1]
        
        // For nums[0->n-2]
        int max_rob_including_0 = maxRob(nums, dp, n-2, 0);
        
        // For nums[1->n-1]
        dp = vector<int>(n+1, -1);
        int max_rob_excluding_0 = maxRob(nums, dp, n-1, 1);

        return max(max_rob_including_0, max_rob_excluding_0);
    }

    int maxRob(vector<int>& nums, vector<int>& dp, int index, int starting_index) {
        // Base conditions for the two starting indices
        if (index<0 && starting_index==0) { return 0; }
        if (index<1 && starting_index==1) { return 0; }
        
        if (dp[index] != -1) { return dp[index]; }

        dp[index] = max(maxRob(nums, dp, index-2, starting_index) + nums[index],
                        maxRob(nums, dp, index-1, starting_index));
        return dp[index];
    }
};
// @lc code=end

