/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        
        // Find the point where the mergeing starts
        int i = 0;
        while (i<n && intervals[i][1]<newInterval[0]) {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }


        while (i<n && newInterval[1]>=intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i<n) {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        return res;
    }
};
// @lc code=end

