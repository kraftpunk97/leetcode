/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int max_product = 1;
        vector<int> zero_pos;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                zero_pos.push_back(i);
            } else {
                max_product *= nums[i];
            }
        }
        if (zero_pos.size() > 1) {
            result = vector<int>(n, 0);
        } else if (zero_pos.size() == 1) {
            result = vector<int>(n, 0);
            result[zero_pos[0]] = max_product;
        } else {
            result = vector<int>(n, max_product);
            for (int i=0; i<n; i++) {
                result[i] = max_product / nums[i];
            }
        }
        return result;
    }
};
// @lc code=end

