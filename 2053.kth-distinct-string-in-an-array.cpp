/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> M;

        for (auto str: arr) {
            if (M.count(str) == 0) { M[str] = 1; }
            else { M[str]++; }
        }        

        int count = 0;
        for (auto str: arr) {
            if (M[str] == 1) {
                count++;
                if (count == k) { return str; }
            }
        }

        return "";
    }
};
// @lc code=end

