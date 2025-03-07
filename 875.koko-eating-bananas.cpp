/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        int res = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            long long h_ = timeToFinish(piles, mid);
            if (h_ > h) { left = mid + 1; }
            else  {
                res = mid; 
                right = mid - 1;
            }
        }
        return res;
    }
    
    long long timeToFinish(vector<int>& piles, int k) {
        long long h = 0;
        for (int pile: piles) {
            h += ceil(static_cast<double>(pile)/k);
        }
        return h;
    }
};
// @lc code=end

