/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> D(n+1, vector<int>(5, 0));
        
        // Init
        for (int j=0; j<5; j++) {
            D[1][j] = 1;
        }

        for (int i=2; i<=n; i++) {
            for (int j=4; j>=0; j--) {
                for (int k=4; k>=j; k--) {
                    D[i][j] += D[i-1][k];
                }
            }
        }

        return D[n][0] + D[n][1] + D[n][2] + D[n][3] + D[n][4];
    }
};
// @lc code=end

