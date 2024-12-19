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
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        // Two Pointers
        for (int i=0; i<n; i++) {
            if (nums[i] > 0) break;
            if (i>0 && nums[i]==nums[i - 1]) { continue; }

            int L = i + 1;
            int R = n - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum < 0) { L++; }
                if (sum > 0) { R--; }
                if (sum == 0) {
                    result.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while (L<R && nums[L]==nums[L-1]) { L++; }
                }
            }
        }
        
        return result;
    }
};
// @lc code=end

