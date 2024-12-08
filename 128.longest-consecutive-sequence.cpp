/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        sort(nums.begin(), nums.end());
        int max_consec = 1;
        int curr_consec = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1]+1==nums[i]) {
                curr_consec++;
                max_consec = max(curr_consec, max_consec);
            } else if (nums[i-1] == nums[i]) {
                
            } else {
                curr_consec = 1;
            }
        } 
        return max_consec;
    }
};
// @lc code=end

