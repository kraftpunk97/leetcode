/*
 * @lc app=leetcode id=2940 lang=cpp
 *
 * [2940] Find Building Where Alice and Bob Can Meet
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto query: queries) {
            int a = query[0];
            int b = query[1];
            result.emplace_back(oneQuery(heights, a, b));
        }
        return result;
    }

    int oneQuery(vector<int>& heights, int alice, int bob) {
        if (alice == bob) { return bob; }

        int left = min(alice, bob);
        int right = max(alice, bob);

        int left_height = heights[left];
        int right_height = heights[right];

        if (left_height < right_height) { return right; }
        else {
            int n = heights.size();
            for (int i=right+1; i<n; i++) {
                if (heights[i] > left_height) { return i; }
            }
            return -1;
        }
    }
    
    struct TreeNode {
        int val;
        int left_idx;
        int right_idx;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val, int left_idx, int right_idx, TreeNode* left, TreeNode* right) : val(val), left_idx(left_idx), right_idx(right_idx), left(left), right(right) {}
        TreeNode(int val, int left_idx, int right_idx) { TreeNode(val, left_idx, right_idx, nullptr, nullptr); }
        int calcMid() { return (left_idx+right_idx) / 2; }
    };

    TreeNode* buildST(vector<int>& heights, int l, int r) {
        if (l == r) { return new TreeNode(heights[r], l, r); }
        else {
            int mid = (l+r) / 2;
            TreeNode* left = buildST(heights, l, mid);
            TreeNode* right = buildST(heights, mid+1, r);
            int val = max(left->val, right->val);
            return new TreeNode(val, l, r, left, right);
        }
    }

    int queryST(int l, int r, TreeNode* node) {
        if (node->right_idx<l || r<node->left_idx) { return INT_MIN; }
        if (l==node->left_idx && r==node->right_idx) { return node->val; }
        int mid = node->calcMid();
        int left_val = queryST(l, mid, node->left);
        int right_val = queryST(mid+1, r, node->right);
        return max(left_val, right_val);
    }
};
// @lc code=end
  
