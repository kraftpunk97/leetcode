/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int counter = 0;
        for (auto& row: matrix) {
            for (int& val: row){
                if (val == target) {
                    counter++;
                }
            }
        }
        // Calculate prefix matrix
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix_matrix;
        fillPrefixMatrix(prefix_matrix, matrix); // O(n*m)
        // For each (r1, r2), we can find the largest sum of a submatrix that uses every row in [r1, r2]
        // in linear time using a sliding window.
        for (int r1=0; r1 < m; r1++) {
            for (int r2=r1; r2 < m; r2++) {
                for (int c1=0; c1<n; c1++) {
                    for (int c2=c1; c2<n; c2++) {
                        if (c1 == c2 && r1 == r2) {
                            continue;
                        }
                        int submatrix_sum = sumSubMatrix(prefix_matrix, r1, c1, r2, c2);
                        if (submatrix_sum == target) {
                            counter++;
                        }
                    }
                }
            }
        }
        return counter;
    }

    void printMatrix(vector<vector<int>>& matrix) {
        for (auto& row: matrix) {
            for (int val: row) {
                cout << val << " ";
            }
            cout << '\n';
        }
    }

    void fillPrefixMatrix(vector<vector<int>>& prefix_matrix, vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> zero_row;
        for (int j=0; j<=n; j++) {
            zero_row.push_back(0);
        }
        prefix_matrix.push_back(zero_row);

        for (int i=1; i<=m; i++) {
            vector<int> row;
            row.push_back(0);
            for (int j=1; j<=n; j++) {
                row.push_back(prefix_matrix[i-1][j] + row[j-1] - prefix_matrix[i-1][j-1] + matrix[i-1][j-1]);
            }
            prefix_matrix.push_back(row);
        }
    } // o(m*n)

    int sumSubMatrix(vector<vector<int>>& prefix_matrix, int a, int b, int A, int B) {
        return prefix_matrix[A+1][B+1] - prefix_matrix[a][B+1] - prefix_matrix[A+1][b] + prefix_matrix[a][b];
    } // O(1)
};
// @lc code=end

int main() {
    vector<vector<int>> matrix = {vector<int>({1, -1}), vector<int>({-1, 1})};
    int target = 0;

    Solution s;
    cout << s.numSubmatrixSumTarget(matrix, target) << '\n';
    return 0;
}