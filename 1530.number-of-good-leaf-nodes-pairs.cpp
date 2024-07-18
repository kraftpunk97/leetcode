/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
    struct NodeStruct {
        vector<TreeNode*> connections;
        bool is_leaf;
    };

    int countPairs(TreeNode* root, int distance) {
        // Create a map of all the nodes connected to a node (parent and child)...
        // And whether or not that node is a leaf
        unordered_map<TreeNode*, NodeStruct> graph;
        vector<TreeNode*> leaf_vector;
        
        NodeStruct root_node;  // Adding the root node to the graph
        graph[root] = root_node;

        traverseTree(root, graph, leaf_vector);
        
        // At this time, we have a graph layout of the whole tree,
        // And we know of all the leaves

        unordered_map<TreeNode*, bool> seen;
        int max_depth = distance;
        int counter = 0;
        
        for (auto leaf_node: leaf_vector) {
            for (auto kv: graph) {  // Reset the seen hashmap
                seen[kv.first] = false;
            }
            measuredDFS(leaf_node, graph, seen, max_depth, counter);  // Apply DFS from each leaf node, not going beyond the given distance from the leaf node.
            counter--;  // Check the if statement in measuredDFS to understand why this was done.
        }

        return counter/2;
    }

    void traverseTree(TreeNode* root_node, unordered_map<TreeNode*, NodeStruct>& graph, vector<TreeNode*>& leaf_vector) {
        if (root_node->left==nullptr && root_node->right==nullptr) {
            // This is a leaf
            graph[root_node].is_leaf = true;
            leaf_vector.push_back(root_node);
        } else {
            graph[root_node].is_leaf = false; // This node is not a leaf
            if (root_node->left != nullptr) { // For each child
                NodeStruct node_struct;
                node_struct.connections.push_back(root_node); // Add this node to its child's connections
                graph[root_node].connections.push_back(root_node->left);  // Add the child to this node's connections
                graph[root_node->left] = node_struct; // Add it to the graph
                traverseTree(root_node->left, graph, leaf_vector); // Traverse this branch further
            }
            if (root_node->right != nullptr) {
                NodeStruct node_struct;
                node_struct.connections.push_back(root_node);
                graph[root_node].connections.push_back(root_node->right);
                graph[root_node->right] = node_struct;
                traverseTree(root_node->right, graph, leaf_vector);
            }
        }
    }

    void measuredDFS(TreeNode* curr_node, unordered_map<TreeNode*, NodeStruct>& graph,
                     unordered_map<TreeNode*, bool>& seen,  int max_depth, int& counter) {
        if (seen[curr_node]) return;  // If already seen this node, then do nothing
        if (max_depth < 0) return;  // If we have exceeded depth, then do nothing

        seen[curr_node] = true; // Immediately mark this node as seen if this is a new node

        // One gotcha that we should be aware of here is that if curr_node itself is a leaf,
        // Then the following if statement will erroneously increment the counter by one.
        // We can compensate for that by decreementing it by one after calling measuredDFS in the main function
        if (graph[curr_node].is_leaf) { // If this is a leaf, then we have encountered a leaf while within valid distance
            counter++;                  // This is a valid leaf-pair then
        }

        auto connections = graph[curr_node].connections;
        for (auto node: connections) {  // Explore other nodes that are connected to this one (standard DFS shenanigans)
            measuredDFS(node, graph, seen, max_depth-1, counter);
        }
        
    }
};
// @lc code=end

