/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 */

#include <vector>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Traverse the entire tree. 
        // Check wether a node is to be deleted
        // If yes, then add its children to the root list
        vector<TreeNode*> roots;
        roots.push_back(root);
        traverseTree(root, to_delete, roots);
        return roots;    
    }

    bool traverseTree(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& roots) {
        if (root == nullptr) return false; // Can't do anything with a nullptr
        if (to_delete.size() < 1) return false; // Nothing to look for if the to_delete list is empty.

        bool was_deleted = false;
        auto itr = find(to_delete.begin(), to_delete.end(), root->val);
        if (itr != to_delete.end()) { // Found a node to be deleted
            auto roots_itr = find(roots.begin(), roots.end(), root);
            if (roots_itr != roots.end()) { // If this node has been classified as a root, then remove it from the list
                 roots.erase(roots_itr);
            }

            // Add its children to the roots list
            if (root->left != nullptr) roots.push_back(root->left);
            if (root->right != nullptr) roots.push_back(root->right);
            
            // Remove the val from the to_delete list
            to_delete.erase(itr);
            was_deleted = true;
        }

        if (traverseTree(root->left, to_delete, roots)) { // If while traversing the tree, we find a node is to be deleted, then sever the link to that node
            root->left = nullptr;
        } 
        if (traverseTree(root->right, to_delete, roots)) {
            root->right = nullptr;
        }
        return was_deleted;
    }
};
// @lc code=end

