/*
 * @lc app=leetcode id=2998 lang=cpp
 *
 * [2998] Minimum Number of Operations to Make X and Y Equal
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        bool done = false;
        int min_moves = __INT_MAX__;
        bfs(x, done, 0, min_moves, y);
        return min_moves;
    }

    void bfs(int x, bool& done, int num_moves, int& min_moves, int y) {
        if (y >= x) {
            num_moves += y-x;
            done = true;
            min_moves = min(min_moves, num_moves);
            return;
        }

        if (x % 5 == 0) {
            bfs(x/5, done, num_moves+1, min_moves, y);
        }
        if (x % 11 == 0) {
            bfs(x/11, done, num_moves+1, min_moves, y);
        }
        bfs(x-1, done, num_moves+1, min_moves, y);
    }

    void printMat(int* dp, int x, int y) {
        for (int i=y; i<=x; i++) {
            cout << dp[i] << ' ';
        }
        cout << '\n';
    }
};
// @lc code=end

