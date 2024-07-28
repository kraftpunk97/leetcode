/*
 * @lc app=leetcode id=3228 lang=cpp
 *
 * [3228] Maximum Number of Operations to Move Ones to the End
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int ctr = 0;
        int one_counter = 0;
        int ops_counter = 0;
        while (ctr<n) {
            while (ctr<n && s[ctr]=='0') {
                ctr++;
            }

            ops_counter += one_counter;
            while(ctr<n && s[ctr]=='1') {
                one_counter++;
                ctr++;
            }
        }

        return ops_counter;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "1001101";
    cout << sol.maxOperations(s) << '\n';
    return 0;
}