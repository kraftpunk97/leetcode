/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result = "";
        unordered_map<char, int> hm;
        for (char c: s) { hm[c] += 1; }
        char c = 'z';
        while (c >= 'a') {
            if (hm[c] != 0) {
                int num_added_chars = min(repeatLimit, hm[c]);
                for (int i=1; i<=num_added_chars; i++) {
                    result += c;
                    hm[c]--;
                }
                if (hm[c] != 0) { // Find the next biggest 'c' for which hm[c] != 0
                    char temp_c = c-1;
                    while (temp_c>='a' && hm[temp_c]==0) { temp_c--; }
                    if (temp_c < 'a') { // We have run out of options; exit
                        break;
                    } else {
                        result += temp_c;
                        hm[temp_c]--;
                    }
                }
            }
            if (hm[c] <= 0) { c--; }
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution sol;
    cout << sol.repeatLimitedString("jwqyyngextfizadbrydpvqjinkjcyplwfolxmjisjjce", 26) << '\n';
    return 0;
}
