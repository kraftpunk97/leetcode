/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_table;
        for (int num: nums) {
            hash_table[num]++;
        }
        vector<pair<int, int>> temp_vector(hash_table.begin(), hash_table.end());
        sort(temp_vector.begin(), temp_vector.end(), [](pair<int, int>a, pair<int, int>b) {
            return a.second > b.second;
        });
        vector<int> result;
        for (int i=0; i<k; i++) {
            result.push_back(temp_vector[i].first);
        }
        return result;
    }
};
// @lc code=end

