/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        unordered_map<int, vector<int>> umap;
        for (int idx=0; idx<nums.size(); idx++) {
            vector<int> temp;
            int num = nums[idx];
            try {
                temp = umap.at(target-num);
                result = vector<int>({idx, temp[1]});
                break;
            } catch(...) {
                umap.insert({num, vector<int>({target-num, idx})});
                continue;
            }
        }
        return result;
    }
};
// @lc code=end

