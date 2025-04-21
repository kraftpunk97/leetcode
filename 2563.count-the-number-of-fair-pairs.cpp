/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.begin());

        int n = nums.size();
        int res = 0;

        int L = n-1;
        int R = n-1;
        for (int i = 0; i < n; i++)
        {
            int l = lower - nums[i];
            int r = upper - nums[i];
            
            L = leftBinSearch(nums, l, i+1, L);
            R = rightBinSearch(nums, r, L, R);

            res += (long long)R - L + 1;
        }

        return res;
    }

    int leftBinSearch(vector<int> &nums, int target, int low, int high)
    {
        // low ends up at the first occurence (if exists)
        int n = nums.size();
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    int rightBinSearch(vector<int> &nums, int target, int low, int high)
    {
        // high ends up at the last occurance (if exists)
        int n = nums.size();
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};
// @lc code=end
