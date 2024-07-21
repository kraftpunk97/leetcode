/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
 */

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
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
    int start, dest;
    vector<int> stack;
    vector<int> source_stack;
    vector<int> dest_stack;
    int found = 0;

    string getDirections(TreeNode* root, int startValue, int destValue) {
        start = startValue;
        dest = destValue;
        traverseTree(root);

        string res = "";

        int up_counter = 0;
        int s_len = source_stack.size();
        int d_len = dest_stack.size();
        int s_ctr=0, d_ctr=0;

        // How many steps from source up to the lowest common ancestor
        while(s_ctr<s_len && d_ctr<d_len && source_stack[s_ctr]==dest_stack[d_ctr]) {
            s_ctr++; d_ctr++;
        }

        up_counter = s_len - s_ctr;

        for (int i=0; i<up_counter; i++) {
            res += 'U';
        }

        // From LCM, the directions to dest
        while (d_ctr < d_len) {
            if (dest_stack[d_ctr] == 1) {
                res += 'R';
            } else {
                res += 'L';
            }
            d_ctr++;
        }

        return res;
    }

    void traverseTree(TreeNode* curr_node) {
        if (found > 1) return;
        
        if (curr_node->val==start || curr_node->val==dest) {
            // Found one of the endpoints
            found++;
            

            // Save the stack state
            if (curr_node->val == start) {
                source_stack = vector<int>(stack);

            } else {
                dest_stack = vector<int>(stack);
            }
        }

        if (curr_node->left != nullptr) {
            // Go left
            stack.push_back(0);
            traverseTree(curr_node->left);
            stack.pop_back();
        }

        if (curr_node->right != nullptr) {
            // Go right
            stack.push_back(1);
            traverseTree(curr_node->right);
            stack.pop_back();
        }
    }
};
// @lc code=end

