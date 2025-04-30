/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
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
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int res = -1;
        int count = 0;
        traverse(root, count, k, res);
        return res;
    }

    void traverse(TreeNode *node, int &count, int k, int &res)
    {
        if (res != -1)
        {
            return;
        }

        if (node != nullptr)
        {
            traverse(node->left, count, k, res);
            count += 1;
            if (count == k)
            {
                res = node->val;
            }
            traverse(node->right, count, k, res);
        }
    }
};
// @lc code=end
