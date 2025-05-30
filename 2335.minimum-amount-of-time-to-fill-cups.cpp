/*
 * @lc app=leetcode id=2335 lang=cpp
 *
 * [2335] Minimum Amount of Time to Fill Cups
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int maxTimeToFillAnyType = *max_element(amount.begin(), amount.end());
        int timeToFillTwoCups = (amount[0] + amount[1] + amount[2] + 1) / 2;
        return max(maxTimeToFillAnyType, timeToFillTwoCups);
    }
};
// @lc code=end
