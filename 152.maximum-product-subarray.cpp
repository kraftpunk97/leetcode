/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return moddedKadane(nums);
    }

    int moddedKadane(vector<int>& nums) {
        int currMinProd = 1;
        int currMaxProd = 1;
        int globalMax = nums[0];
        bool contains_zero = false;
        for (int num: nums) {
            if (num == 0) {
                currMaxProd = 1;
                currMinProd = 1;
                contains_zero = true;
                continue;
            }
            int temp = currMaxProd * num;
            currMaxProd = max(currMaxProd*num, max(num*currMinProd, num));
            currMinProd = min(temp, min(num*currMinProd, num));
            globalMax = max(globalMax, currMaxProd);
        }
        if (contains_zero && globalMax<0) { globalMax = 0; }
        return globalMax;
    }
};
// @lc code=end

