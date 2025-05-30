/*
 * @lc app=leetcode id=2918 lang=cpp
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0;
        int zero1 = 0;
        for (int num: nums1) 
        {
            s1 += num;
            zero1 += num == 0 ? 1 : 0;
        }

        long long s2 = 0;
        int zero2 = 0;
        for (int num: nums2) 
        {
            s2 += num;
            zero2 += num == 0 ? 1 : 0;
        }

        if (zero1 == 0)
        {
            if (s2 + zero2 > s1)
            {
                return -1;
            }
        }
        if (zero2 == 0)
        {
            if (s1 + zero1 > s2)
            {
                return -1;
            }
        }
        
        long long s_diff = abs(s1 - s2);
        int zero_diff = abs(zero1 - zero2);
        return max(s1 + zero1, s2 + zero2);
    }
};
// @lc code=end

