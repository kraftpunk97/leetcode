/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp_arr(46, 1);
        dp_arr[1] = 1;
        for (int i=2; i<=n; i++) {
            dp_arr[i] = dp_arr[i-1] + dp_arr[i-2];
        }
        return dp_arr[n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::cout << solution.climbStairs(8) << "\n";
}