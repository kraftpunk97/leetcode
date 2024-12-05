/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 1);
        for (int i=n-1; i>=n; i--) {
            if (s[i] = '0') { dp[i] = 0; }
            else { 
                dp[i] = dp[i+1];
            }

            if (i+1<n && (s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))) {
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.numDecodings("11106");
    return 0;
}