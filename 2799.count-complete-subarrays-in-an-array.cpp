/*
 * @lc app=leetcode id=2799 lang=cpp
 *
 * [2799] Count Complete Subarrays in an Array
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> left_hm;
        unordered_map<int, int> right_hm;
        for (int i = 0; i < n; i++)
        {
            left_hm[nums[i]] = i;
            if (right_hm.count(nums[i]) == 0)
            {
                right_hm[nums[i]] = i;
            }
        }

        int minn = INT_MAX;
        for (auto itr = left_hm.begin(); itr != left_hm.end(); itr++)
        {
            minn = min(minn, itr->second);
        }
        int maxx = -1;
        for (auto itr = right_hm.begin(); itr != right_hm.end(); itr++)
        {
            maxx = max(maxx, itr->second);
        }

        if (minn >= maxx)
        {
            minn = INT_MAX;
            for (auto itr = right_hm.begin(); itr != right_hm.end(); itr++)
            {
                minn = min(minn, itr->second);
            }
        }

        cout << minn << ' ' << maxx << '\n';
        
        if (minn == maxx)
        {
            return n*(n+1) / 2;
        }


        int left = minn + 1;
        int right = n - maxx;

        return left * right;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{1898,370,822,1659,1360,128,370,360,261,1898};
    cout << s.countCompleteSubarrays(nums) << '\n';
    return 0;
}