/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0); // 0
        if (n==0) {
            return res;
        }
        res.push_back(1); // 1
        for (int i=2; i<=n; i++) {
            if (i%2==0) {
                res.push_back(res[i/2]);
            } else {
                res.push_back(res[i/2]+1);
            }
        }
        return res;
    }
};
// @lc code=end

