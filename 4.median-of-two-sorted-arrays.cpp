/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0) {
            return n2%2 == 0 ? (nums2[n2/2] + nums2[(n2/2)-1]) / 2 : nums2[n2/2];
        }
        if (n2 == 0) {
            return n1%2 == 0 ? (nums1[n1/2] + nums1[(n1/2)-1]) / 2 : nums1[n1/2];
        }
        return twoPointers(nums1, nums2);
    }

    double twoPointers(vector<int>& nums1, vector<int>& nums2) {
        int totSize = nums1.size() + nums2.size();

        int ptr1 = 0;
            int ptr2 = 0;
            int ctr = (totSize/2) - 1;
            while (ctr--) {
                if (nums1[ptr1] <= nums2[ptr2]) {
                    ptr1++;
                } else {
                    ptr2++;
                }
            }

        if (totSize % 2 == 0) { // If Even
            return static_cast<double>(nums1[ptr1]+nums2[ptr2]) / 2;
        } else {
            return static_cast<double>(max(nums1[ptr1], nums2[ptr2]));
        }

    }
};
// @lc code=end

