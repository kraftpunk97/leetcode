/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        // Use Dynamic Programming
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'b') { b_count++; }
            else {
                // The two cases are either keep the 'a' or delete it.
                min_deletions = min(min_deletions+1, b_count);
            }
        }
        return min_deletions;
    }
};
// @lc code=end

int main() {
    string s = "aababbab";
    Solution sol;
    sol.minimumDeletions(s);
    return 0;
}