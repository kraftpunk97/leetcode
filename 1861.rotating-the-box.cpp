/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> rotatedBox(n, vector<char>(m, '.'));
        
        for (int i=0; i<m; i++) {
            // For every row
            // First find the obstaclle from the end
            // Also count the number of stones while we are at it.
            int obstacleEnd = n;
            while (obstacleEnd >= 0) {
                int obstacleBegin = obstacleEnd - 1;
                int stoneCounter = 0;
                while (obstacleBegin>=0 && box[i][obstacleBegin]!='*') { 
                    if (box[i][obstacleBegin] == '#') { 
                        stoneCounter++;
                        box[i][obstacleBegin] = '.';
                    }
                    obstacleBegin--;
                }           
                
                // Drop all stones from obstacleBegin+1-stoneCounter to obstacleEnd-1;
                for (int ctr=0; ctr<stoneCounter; ctr++) {
                    box[i][obstacleEnd-1-ctr] = '#';
                }
                obstacleEnd = obstacleBegin;
            }
        }

        printMat(box);

        // Copy the vector matrix
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                rotatedBox[j][m-i-1] = box[i][j];
            }
        }

        return rotatedBox;
    }

    void printVec(vector<char>& vec) {
        for (auto elem: vec) {
            cout << elem << ' ';
        }
    }

    void printMat(vector<vector<char>>& mat) {
        for (auto vec: mat) {
            printVec(vec);
            cout << '\n';
        }
    }
};
// @lc code=end

int main() {
    Solution s;
}