/*
 * @lc app=leetcode id=2145 lang=cpp
 *
 * [2145] Count the Hidden Sequences
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long net = 0, minn = 0, maxx = 0;
        for (int d: differences)
        {
            net += d;
            minn = min(minn, net);
            maxx = max(net, maxx);
        }

        int range = maxx - minn;
        int numArrays = upper - lower + 1 - range;
        return max(numArrays, 0);
    }
};
// @lc code=end

