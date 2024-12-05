/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */
#include <iostream>
#include <vector>

using namespace std;


// @lc code=start
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int negCounter = 0;
        long long sum = 0;
        int smallestAbsValue = abs(matrix[0][0]);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                sum += abs(matrix[i][j]);
                negCounter += matrix[i][j] < 0;
                smallestAbsValue = smallestAbsValue<abs(matrix[i][j]) ? smallestAbsValue : abs(matrix[i][j]);
            }
        }

        if (negCounter%2 == 0) { return sum; }
        else { return sum - 2*smallestAbsValue; }
    }

    inline int abs(int num) { return num<0 ? -num : num; }
};
// @lc code=end

