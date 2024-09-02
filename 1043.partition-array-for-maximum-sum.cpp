/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> D(n, vector<int>(n, 0));

        // Init
        for (int i=0; i<n; i++) {
            D[i][i] = arr[i];
        }

        for (int start=0; start<n; start++) {
            int curr_max = arr[start];
            for (int len=1; len<min(k, n-start); len++) {
                int new_elem = arr[start+len-1];
                curr_max = curr_max<new_elem ? new_elem : curr_max;
                
            }
        }
    }
};
// @lc code=end

