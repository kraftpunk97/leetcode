/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_len;
        for (int i=0; i<n; i++) {
            max_len.push_back(1);
        }

        for(int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    max_len[i] = max(max_len[i], max_len[j]+1);
                }
            }
        }
        
        int max_max_len = 0;
        for (int& val: max_len) {
            max_max_len = max(val, max_max_len);
        }
        return max_max_len;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    Solution sol;
    cout << sol.lengthOfLIS(nums) << '\n';
    return 0;
}