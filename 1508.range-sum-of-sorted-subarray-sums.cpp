/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Calculate sum
        vector<int> sums((n*(n+1))/2, 0);
        int sums_ctr = 0;
        int sum;
        const int mod = 1e9 + 7;
        for (int i=0; i<n; i++) {
            sum = 0;
            for (int j=i; j<n; j++) {
                int adding = nums[j];
                sum += adding;
                sums[sums_ctr] = sum;
                sums_ctr++;
            }
        }

        // sort it        
        sort(sums.begin(), sums.end());

        // retrieve sum
        sum = 0;
        for (int i=left-1; i<=(right-1); i++) {
            sum  = (sum + sums[i]) % mod;
        }

        return sum;
    }
};
// @lc code=end

