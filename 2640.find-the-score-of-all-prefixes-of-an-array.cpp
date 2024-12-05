/*
 * @lc app=leetcode id=2640 lang=cpp
 *
 * [2640] Find the Score of All Prefixes of an Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> result;
        long long prefixSum = 2 * nums[0];
        int maxElem = nums[0];
        result.push_back(prefixSum);
        for (int i=1; i<n; i++) {
            if (nums[i] > maxElem) { maxElem = nums[i]; }
            prefixSum += nums[i] + maxElem;
            result.push_back(prefixSum);
        }
        return result;
    }
};
// @lc code=end

