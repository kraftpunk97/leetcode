/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <cstdio>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = nums[0];
        for (auto num: nums)
        {
            
            currSum = max(0, currSum);
            currSum += num;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
// @lc code=end

