/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        /*
        Well, we could definitely use DP for this shit.
        */
        /* Dynamic Programming Approach (Leads to MLE)
        int n = height.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return TopDown(height, dp, 0, n-1);
        */

        ///* Prefix and Suffix Arrays
        return PrefixSuffixArrays(height);
        //*/

    }

    int PrefixSuffixArrays(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        
        // Fill in the prefix and suffix arrays
        for (int i=1; i<n; i++) {
            left_max[i] = max(left_max[i-1], height[i-1]);
            right_max[n-i-1] = max(right_max[n-i], height[n-i]);
        }

        // Find the capacity held at each index
        int capacity = 0;
        for (int i=0; i<n; i++) {
            capacity += max(min(left_max[i],right_max[i])-height[i], 0);
        }
        return capacity;
    }

    int TopDown(vector<int>& height, vector<vector<int>>& dp, int L, int R) {
        if (dp[L][R] != -1) { return dp[L][R]; }
        if (R-L < 2) { 
            dp[L][R] = 0;
            return 0;
        }

        // Find the max middle pillar in height[L+1...R-1]
        int max_pillar_idx = L+1;
        for (int i=L+2; i<=R-1; i++) {
            max_pillar_idx = height[i]>height[max_pillar_idx] ? i : max_pillar_idx;
        }

        dp[L][R] = TopDown(height, dp, L, max_pillar_idx) + TopDown(height, dp, max_pillar_idx, R);
        if (height[L]>height[max_pillar_idx] && height[max_pillar_idx]<height[R]) {
            dp[L][R] += (min(height[L],height[R]) - height[max_pillar_idx]) * (R-L-1);
        }
        return dp[L][R];
    }
};
// @lc code=end

