/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class SegementTree {
public:
    int n;
    vector<int> tree;

    SegementTree(vector<int>& nums, int value, int L, int R) {
        n = 4 * nums.size();
        tree = vector<int>(n, 0);
    }

    void build(vector<int>& nums, int value, int L, int R) {
        if (L == R) {
            tree[value] = nums[L];
        } else {
            int M = (L + R) / 2;
            build(nums, value, L, M);
            build(nums, value, M+1, R);
            // How would you calculate the length of the longest subsequence?
        }
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int globalMax = 0;

    }
};
// @lc code=end

