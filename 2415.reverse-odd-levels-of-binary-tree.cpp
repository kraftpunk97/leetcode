/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        return BFS(root);
    }

    TreeNode* BFS(TreeNode* root) {
        vector<TreeNode*> processing_q;

        int curr_level = 0;
        TreeNode* curr_node = root;

        processing_q.push_back(root);

        while (!processing_q.empty()) {
            vector<TreeNode*> temp_vec;
            for (auto node: processing_q) {
                if (node->left != nullptr) { temp_vec.push_back(node->left); }
                if (node->right != nullptr) { temp_vec.push_back(node->right); }
            }
            
            processing_q = temp_vec;

            if (curr_level%2 == 0) { // If current level is even, then the children will be odd
                int n = processing_q.size();
                for (int i=0; i<n/2; i++) {
                    TreeNode* node1 = processing_q[i];
                    TreeNode* node2 = processing_q[n-i-1];
                    
                    // Swap vals but don't swap children
                    int temp_val = node1->val;
                    node1->val = node2->val;
                    node2->val = temp_val;
                }
            }
            curr_level++;
        }

        return root;
    }
};
// @lc code=end

