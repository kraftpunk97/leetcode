/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        if (nums[l] < nums[r]) { return nums[0]; }
        while (r-l > 1) {
            int m = (l+r) / 2;
            if (nums[l] < nums[m]) { 
                // We haven't seen the inflection point yet.
                // Look to the right of m.
                l = m;
            } else { // nums[l] > nums[m]
                // The inflection point is behind us
                // Look to the left of m.
                r = m;
            }
        }
        return min(nums[l], nums[r]);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{5, 1, 2, 3, 4};
    cout << s.findMin(nums) << '\n';
}
