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
        int maxSum = nums[0];
        int currSum = 0;
        for (int& i: nums) {
            currSum = max(currSum, 0);
            currSum += i;
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
// @lc code=end

