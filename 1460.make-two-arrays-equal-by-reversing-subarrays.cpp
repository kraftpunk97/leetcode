/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> count(1001, 0);
        int n = target.size();
    
        for (int i=0; i<n; i++) {
            count[target[i]]--;
            count[arr[i]]++;
        }

        for (auto val: count) {
            if (val != 0) { return false; }
        }

        return true;
    }
};
// @lc code=end

