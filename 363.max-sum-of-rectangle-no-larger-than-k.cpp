/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */
#include <vector>
#include <iostream>


using namespace std;

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> prefix;
        prefixMatrix(prefix, matrix);
        
        int max_sum = -100000;
        for(int r1=0; r1<m; r1++) {
            for (int r2=r1; r2<m; r2++) {
                for (int c1=0; c1<n; c1++) {
                    for (int c2=c1; c2<n; c2++) {
                        int submatrix_sum = sumSubmatrix(prefix, r1, c1, r2, c2);
                        if (max_sum < submatrix_sum  && submatrix_sum <= k) {
                            max_sum = submatrix_sum;
                            if (submatrix_sum == k) {
                                return submatrix_sum;
                            }
                        } 
                    }
                }
            }
        }
        return max_sum;
    }

    void prefixMatrix(vector<vector<int>>& prefix, vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> first_row;
        for (int j=0; j<=n; j++) {
            first_row.push_back(0);
        }
        prefix.push_back(first_row);

        for (int i=1; i<=m; i++) {
            vector<int> row;
            row.push_back(0);
            for (int j=1; j<=n; j++) {
                row.push_back(prefix[i-1][j] + row[j-1] - prefix[i-1][j-1] + matrix[i-1][j-1]);
            }
            prefix.push_back(row);
        }
    }

    int sumSubmatrix(vector<vector<int>>& prefix, int a, int b, int A, int B) {
        return prefix[A+1][B+1] - prefix[A+1][b] - prefix[a][B+1] + prefix[a][b];
    }

    void printMatrix(vector<vector<int>>& matrix) {
        for (auto& row: matrix) {
            for (int& val: row) {
                cout << val << " ";
            }
            cout << '\n';
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{2, 2, -1}};
    int k = 0;
    cout << sol.maxSumSubmatrix(matrix, k) << '\n';
    return 0;
}

