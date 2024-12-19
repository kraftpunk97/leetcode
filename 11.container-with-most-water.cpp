/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        // Brute Force
        int max_capacity = 0;
        int L = 0;
        int R = n-1;
        while (L < R) {
            int dist = R - L;
            int capacity = min(height[L], height[R]) * dist;
            max_capacity = max(capacity, max_capacity);
            if (height[L] <= height[R]) { L++; }
            else { R--; }
        }
        return max_capacity;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> height{8, 7, 2, 1};
    cout << sol.maxArea(height) << '\n';
    return 0;
}