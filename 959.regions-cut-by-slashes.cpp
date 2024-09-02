/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(3*n, vector<int>(3*n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int base_row = 3*i;
                int base_col = 3*j;
                if (grid[i][j] == '\\') {
                    mat[base_row][base_col]     = 1;
                    mat[base_row+1][base_col+1] = 1;
                    mat[base_row+2][base_col+2] = 1;
                }
                if (grid[i][j] == '/') {
                    mat[base_row][base_col+2]   = 1;
                    mat[base_row+1][base_col+1] = 1;
                    mat[base_row+2][base_col]   = 1;
                }
            }
        }
        int counter = 0;
        for (int i=0; i<3*n; i++) {
            for (int j=0; j<3*n; j++) {
                if (mat[i][j] == 0) {
                    floodFill(mat, i, j);
                    counter++;
                }
            }
        }

        //printMat(mat);
        return counter;
    }

    void floodFill(vector<vector<int>> &mat, int i, int j) {
        int n = mat.size();
        if (i<0 || i>=n) { return; }
        if (j<0 || j>=n) { return; }

        if (mat[i][j] != 0) { return; }

        mat[i][j] = 2;
        floodFill(mat, i+1, j);
        floodFill(mat, i-1, j);
        floodFill(mat, i, j+1);
        floodFill(mat, i, j-1);
    }

    template <typename T>
    void printMat(vector<vector<T>> &mat) {
        for (auto vec: mat) {
            for (auto elem: vec) {
                cout << elem << ' ';
            }
            cout << '\n';
        }
    }
};
// @lc code=end

int main() {
    vector<string> grid{"\\/","/\\"};
    Solution s;
    s.regionsBySlashes(grid);
    return 0;
}