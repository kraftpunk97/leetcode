/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> resSet;
        sort(nums.begin(), nums.end());
        for (int b=1; b<n-2; b++) {
            for (int c=b+1; c<n-1; c++) {
                int a = b - 1;
                int d = c + 1;
                while (a>=0 && d<n) {
                    long long s = (long long) nums[a] + nums[b] + nums[c] + nums[d];
                    if (s < target) { d++; } 
                    else if (s > target) { a--; }
                    else {
                        resSet.insert(vector<int>({nums[a], nums[b], nums[c], nums[d]}));
                        d += 1;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (auto vec: resSet) {
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> res = s.fourSum(nums, 0);
    for (auto vec: res) { 
        for (auto num: vec) { cout << num << ' '; }
        cout << '\n';
    }
    return 0;
}