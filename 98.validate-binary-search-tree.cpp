/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    bool isValidBST(TreeNode* root) {
        stack<int> stck;
        inorderTraversal(root, stck);
        // Time to pop;
        int current_val;
        do {
            current_val = stck.top();
            stck.pop();
            if (!stck.empty() && current_val <= stck.top()) {
                return false;
            }
        } while (!stck.empty());
        return true;
    }

    void inorderTraversal(TreeNode* node, stack<int>& stck) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left, stck);
        stck.push(node->val);
        inorderTraversal(node->right, stck);
    }
};
// @lc code=end

