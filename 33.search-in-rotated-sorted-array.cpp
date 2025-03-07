/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 1) { return nums[0]==target ? 0 : -1; }
        if (n == 2) {
            return nums[0]==target ? 0 : ((nums[1]==target) ? 1 : -1);
        }
        if (nums[0] < nums[n-1]) { // No rotation
             return binarySearch(nums, 0, n-1, target);
        }

        int l = 0;
        int r = n - 1;
        int inflection = 0;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                inflection = nums[l]<nums[inflection] ? l : inflection;
                break;
            }
            int m = l + ((r-l)/ 2);
            inflection = nums[inflection]<nums[m] ? inflection : m;
            if (nums[l] <= nums[m]) { l = m + 1; }
            else { r = m - 1; }
        }

        if (target < nums.back()) { // Search from inflection to nums.size()-1
            return binarySearch(nums, inflection, n-1, target);
        } else { // Search from 0 to inflection-1.
            return binarySearch(nums, 0, inflection-1, target);
        }
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = l + ((r-l)/2);
            if (target < nums[m]) { r = m - 1; }
            else if (target > nums[m]) { l = m + 1; }
            else { return m; }
        }
        return -1;
    }
};
// @lc code=end

