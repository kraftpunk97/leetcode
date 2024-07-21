/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result(max(m, n));
        vector<int> row_min(m, 0);
        vector<int> col_max(n, 0);

        for (int j=0; j<n; j++) {
            col_max[j] = matrix[0][j];
        }

        for (int i=0; i<m; i++) {
            int min_row = matrix[i][0];
            for (int j=0; j<n; j++) {
                min_row = min(min_row, matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
            row_min[i] = min_row;
        }

        sort(row_min.begin(), row_min.end());
        sort(col_max.begin(), col_max.end());

        auto it = set_intersection(row_min.begin(), row_min.end(), col_max.begin(), col_max.end(), result.begin());
        return vector<int>(result.begin(), it);
    }

    void printArr(vector<int>& arr) {
        for (auto elem: arr) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    void printMat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        cout << "m = " << m << " n = " << n << '\n';
        for (auto row: mat) {
            for (auto elem: row) {
                cout << elem << ' ';
            }
            cout << '\n';
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> matrix{vector<int>{1,10,4,2},vector<int>{9,3,8,7}, vector<int>{15,16,17,12}};
    Solution s;
    s.luckyNumbers(matrix);
    return 0;
}
