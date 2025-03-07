/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <algorithm>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) { return a[0] < b[0]; }
            else { return a[1] < b[1]; }
        });
        vector<vector<int>> output{intervals[0]};
        for (int i=1; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start <= output.back()[1]) {
                output.back()[1] = max(output.back()[1], end);
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }


};
// @lc code=end

