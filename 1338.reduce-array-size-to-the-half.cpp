/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> c;
        for (int i=0; i<arr.size(); i++)
        {
            c[arr[i]] += 1;
        }

        int target = arr.size() / 2;
    }
};
// @lc code=end

