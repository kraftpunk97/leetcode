/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        int n = nums.size();
        // Brute Force
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (nums[i]+nums[j]+nums[k] == 0) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

