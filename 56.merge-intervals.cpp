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
        vector<vector<int>> copy(intervals);
        sort(copy.begin(), copy.end(), [](vector<int>a, vector<int>b){return a[0]!=b[0] ? a[0]<b[0] : a[1]<b[1];});
        auto first_elem_iter = copy.begin();
        for (int i=1; i < copy.size(); i++) {
            if (copy[i-1][0]>=copy[i][0] || copy[i-1][1]>=copy[i][0]) {
                copy[i][0] = min(copy[i][0], copy[i-1][0]);
                copy[i][1] = max(copy[i][1], copy[i-1][1]);
                copy.erase(first_elem_iter+i-1);
                i--;
            }
        }
        return copy;
    }
};
// @lc code=end

