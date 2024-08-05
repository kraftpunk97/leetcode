/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */
#include <iostream>
#include <vector>
#include <unordered_map>

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
    vector<TreeNode*> allPossibleFBT(int n) {
        int num_nodes = 0; 
        vector<TreeNode*> result;
        vector<vector<TreeNode*>> D(n+1, vector<TreeNode*>());

        // Edge cases
        if (n%2 == 0) {
            return {};
        }

        result = allTrees(n, D);
        return result;
    }

    vector<TreeNode*> allTrees(int n, vector<vector<TreeNode*>> &D) {
        // First check if already exists
        if (!D[n].empty()) {
            return D[n];
        }

        if (n == 1) {
            D[n].push_back(new TreeNode());
            return D[n];
        }

        for(int i=1; i<n; i+=2) {
            vector<TreeNode*> children1 = allTrees(i, D);
            vector<TreeNode*> children2 = allTrees(n-1-i, D);

            for (auto tree1: children1) {
                for (auto tree2: children2) {
                    TreeNode* new_root = new TreeNode(0, tree1, tree2);
                    D[n].push_back(new_root);
                }
            }
        }

        return D[n];
    }
};
// @lc code=end


int main() {
    Solution s;
    vector<TreeNode*> result = s.allPossibleFBT(7);
    return 0;
}