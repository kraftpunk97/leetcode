/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rows
        for (int row=0; row<9; row++) {
            vector<bool> seen(10, false);
            for (int col=0; col<9; col++) {
                if (board[row][col] != '.') {
                    int val = board[row][col] - '0';
                    if (seen[val]) { return false; }
                    seen[val] = true;
                }
            }
        }

        // Columns
        for (int col=0; col<9; col++) {
            vector<bool> seen(10, false);
            for (int row=0; row<9; row++) {
                if (board[row][col] != '.') {
                    int val = board[row][col] - '0';
                    if (seen[val]) { return false; }
                    seen[val] = true;
                }
            }
        }

        // Sub boxes
        for (int maj_row=0; maj_row<3; maj_row++) {
            for (int maj_col=0; maj_col<3; maj_col++) {
                vector<bool> seen(10, false);
                for (int min_row=0; min_row<3; min_row++) {
                    for (int min_col=0; min_col<3; min_col++) {
                        int row = 3*maj_row + min_row;
                        int col = 3*maj_col + min_col;
                        if (board[row][col] != '.') {
                            int val = board[row][col] - '0';
                            if (seen[val]) { return false; }
                            seen[val] = true;
                        }        
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

