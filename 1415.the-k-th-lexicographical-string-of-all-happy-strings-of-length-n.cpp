/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string getHappyString(int n, int k) {
    auto prem = 1 << (n - 1);
    if (k > 3 * prem)
        return "";
    string s = string(1, 'a' + (k - 1) / prem);
    while (prem > 1) {
        k = (k - 1) % prem + 1;
        prem >>= 1;
        s += (k - 1) / prem == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() != 'c');
    }
    return s;
}
};
// @lc code=end

