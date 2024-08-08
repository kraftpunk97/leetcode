/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    enum directions{right, down, left, up};

    inline void updateDirection(directions &direction) {
        switch(direction) {
            case right: direction = down;
            break;
            case down:  direction = left;
            break;
            case left:  direction = up;
            break;
            case up:    direction = right;
            break;
        }
    }

    inline void updateIJ(directions direction, int &current_i, int &current_j) {
        switch(direction) {
            case right: current_j += 1;
            break;
            case down:  current_i += 1;
            break;
            case left:  current_j -= 1;
            break;
            case up:    current_i -= 1;
        }
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result(rows*cols, vector<int>(2, 0));
        int counter = 0;
        int take_steps = 1; // The number of steps to be taken before each turn
        directions direction = right; // The current direction of progression
        int current_i = rStart;
        int current_j = cStart;
        bool breakout = false; // Boolean variable to let the outer while loop know that the process has completed.

        while(true) {
            for (int step=1; step<=take_steps; step++) {
                if (0<=current_i && current_i<rows && 0<=current_j && current_j<cols) {
                    result[counter][0] = current_i;
                    result[counter][1] = current_j;
                    counter++;
                    if (counter >= rows*cols) { 
                        breakout = true;
                        break;
                    }
                }
                updateIJ(direction, current_i, current_j);
            }
            if (breakout) { break; }
            updateDirection(direction);
            if (direction==left || direction==right) { take_steps++; }
        }

        //printMat(result);
        return result;
    }

    template<typename T>
    void printMat(vector<T> &mat) {
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
    Solution s;
    s.spiralMatrixIII(5, 6, 1, 4);
    return 0;
}
