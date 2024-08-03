/*
 * @lc app=leetcode id=2678 lang=cpp
 *
 * [2678] Number of Senior Citizens
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int senior_ctr = 0;
        for (string detail: details) {
            int age = (detail[11]-'0')*10 + (detail[12]-'0');
            senior_ctr += (age>60);
        }
        
        return senior_ctr;
    }
};
// @lc code=end

