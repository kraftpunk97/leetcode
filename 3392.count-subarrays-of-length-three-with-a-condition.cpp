/*
 * @lc app=leetcode id=3392 lang=cpp
 *
 * [3392] Count Subarrays of Length Three With a Condition
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int count = 0;
        for (int i=2; i<nums.size(); i++)
        {
            if (2 * (nums[i] + nums[i-2]) == nums[i-1])
            {
                count ++;
            }
        }
        return count;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{-1, -4, -1, 4};
    cout << s.countSubarrays(nums) << '\n';
    return 0;
}