/*
 * @lc app=leetcode id=3229 lang=cpp
 *
 * [3229] Minimum Operations to Make Array Equal to Target
 */
#include <vector>

using namespace std;

// @lc code=start
struct stackNode {
    int val;
    stackNode* next;
public:
    stackNode(int value) { val = value; next = nullptr; }
    void push(int value, stackNode* &head) {
        stackNode* new_node = (stackNode*) malloc(sizeof(stackNode*));
        new_node->next = head;
        head = new_node;
    }
    bool pop(stackNode* &head) {
        if (head != nullptr) {
            stackNode* node = head;
            head = head->next;
            free(node);
            return true;
        } else { return false; }
    } 
    int top(stackNode* head) {
        return head->val;
    }
};

class Solution {
    stackNode* head = nullptr;
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n, 0);

        for (int i=0; i<n; i++) {
            diff[i] = target[i] - nums[i];
        }

        // 2D dynamic programming problem
        vector<vector<int>> D(n, vector<int>(n, 0));
        for (int i=0; i<n; i++) {
            D[i][i] = diff[i];
        }
         
    }
};
// @lc code=end

