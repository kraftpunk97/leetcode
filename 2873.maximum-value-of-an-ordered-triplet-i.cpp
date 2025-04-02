/*
 * @lc app=leetcode id=2873 lang=cpp
 *
 * [2873] Maximum Value of an Ordered Triplet I
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixMax(n, nums[0]);
        vector<long long> suffixMax(n, nums[n-1]);
        for (int i=1; i<n; i++) {
            prefixMax[i] = max(prefixMax[i-1], (long long)nums[i]);
            suffixMax[n-i-1] = max(suffixMax[n-i], (long long)nums[n-i-1]);
        }

        long long res = 0;
        for (int j=1; j<n-1; j++) {
            long long i = prefixMax[j-1];
            long long k = suffixMax[j+1];
            res = max(res, (i-nums[j])*k);
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> arr = {1,10,3,4,19};
    cout << s.maximumTripletValue(arr) << endl;
    return 0;
}