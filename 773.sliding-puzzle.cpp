/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<int> visited_configs;
        
        vector<int> board_(6, 0);
        int ctr = 0;
        int i=0, j=0;

        while (ctr < 6) {
            board_[ctr] = board[i][j];
            ctr++;
            j++;
            if (j == 3) {
                j = 0;
                i++;
            }
        }

        
        bool done = false;
        int dist = 0;
        int min_dist = 0;
        dfs(board_, done, visited_configs, dist, min_dist);

        if (not done) {
            return -1;
        } else {
            return min_dist;
        }
    }

    void dfs(vector<int>& board, bool& done, unordered_set<int>& visited_configs, int dist, int& min_dist) {
        int config = convert_config(board);
        if (config == 123450) { // Found the configuration we wanted.
            done = true;
            if (dist < min_dist) { min_dist = dist; }
            return;
        }

        if (visited_configs.find(config) != visited_configs.end()) { return; } // Already visited this configuration
        
        visited_configs.insert(config);

        // generate moves
        vector<vector<int>> moves = generate_moves(board);

        // Explore all generated moves
        for (auto& move: moves) {
            dfs(move, done, visited_configs, dist+1, min_dist);
        }
    }
    vector<vector<int>> generate_moves(vector<int>& board) {
        // Find the position of 0;
        int zero_pos = 0;
        while (board[zero_pos++]!=0);
        zero_pos--;

        vector<vector<int>> results;
        if (zero_pos < 3) {  // Move Down
            int newzero_pos = zero_pos + 3;
            vector<int> new_config(board);
            int temp = new_config[zero_pos];
            new_config[zero_pos] = new_config[newzero_pos];
            new_config[newzero_pos] = temp;
            results.push_back(new_config);
        } 
        if (zero_pos >= 3) { // Move Up
            int newzero_pos = zero_pos - 3;
            vector<int> new_config(board);
            int temp = new_config[zero_pos];
            new_config[zero_pos] = new_config[newzero_pos];
            new_config[newzero_pos] = temp;
            results.push_back(new_config);
        }
        if (zero_pos!=2 && zero_pos!=5) { // Move left
            int newzero_pos = zero_pos + 1;
            vector<int> new_config(board);
            int temp = new_config[zero_pos];
            new_config[zero_pos] = new_config[newzero_pos];
            new_config[newzero_pos] = temp;
            results.push_back(new_config);
        }
        if (zero_pos!=0 && zero_pos!=3) { // Move Right
            int newzero_pos = zero_pos - 1;
            vector<int> new_config(board);
            int temp = new_config[zero_pos];
            new_config[zero_pos] = new_config[newzero_pos];
            new_config[newzero_pos] = temp;
            results.push_back(new_config);
        }
        return results;
    }

    int convert_config(vector<int>& board) {
        int sum = 0;
        for (int i=0; i<6; i++) {
            sum = 10*sum + board[i];
        }
        return sum;
    }
};
// @lc code=end

