/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0;
        int R = n - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] == target) { return mid; }
            if (target < nums[mid]) { R = mid - 1; }
            else { L = mid + 1; }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums{-1,0,3,5,9,12};
    int target = 2;
    cout << sol.search(nums, target);
    return 0;

}