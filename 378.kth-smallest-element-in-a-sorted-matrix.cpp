/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        int m = matrix.size();

        for (int i=0; i<m; i++) {
            copy(matrix[i].begin(), matrix[i].end(), back_inserter(arr));
        }

        make_heap(arr.begin(), arr.end(), greater<>{});
        
        for (int i=0; i<k-1; i++) {
            pop_heap(arr.begin(), arr.end()-i, greater<>{});
        }
        return arr[0];
    }
};
// @lc code=end

