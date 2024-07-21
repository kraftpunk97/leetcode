/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> result(k, vector<int>(k, 0));
    
        // Topogically sort rowConditions and colConditions
        // Use Kahn's Algorithm because we need to know if the cycles exist
        vector<int> sorted_cols;
        if (kahn(colConditions, sorted_cols, k)) {
            return {};
        }

        vector<int> sorted_rows;
        if (kahn(rowConditions, sorted_rows, k)) { // If a cycle exists, immediately return the empty matrix
            return {};
        }
        
        for (int i=0; i<sorted_rows.size(); i++) {
            // Considering the i-th element of the sorted rows
            int val = sorted_rows[i];
            int j = 0;
            while (j<sorted_cols.size() && sorted_cols[j]!=val) {
                j++;
            }

            if (j==sorted_cols.size()) {
                // This val is not present in sorted_cols
                // Stick it anywhere (preferably at the begining)
                result[i][0] = val;
            } else {
                result[i][j] = val;
            }
        }
    
        return result;
    }

    bool kahn(vector<vector<int>>& conditions, vector<int>& sorted_arr, int k) {
        /* This function accepts the row or col conditions, constructs a graph,
            and returns the topologically sorted array, based on said conditions

            It also returns a boolean value which indicates whether a cycle was detected
            in this graph.

            If a cycle is detected, the sorted_arr is meaningless.
        */
        bool is_cyclic = false;
        vector<vector<int>> graph(k+1, vector<int>(k+1, -2));
        vector<int> in_degree(k+1, -2);
        queue<int> q;
        
        // Construct graph representation
        for (int i=1; i<=k; i++) {
            for (int j=0; j<=k; j++) {
                    graph[i][j] = 0;
                    graph[j][i] = 0;
            }
            in_degree[i] = 0;
        }

        for (auto& cond: conditions) {
            int from = cond[0];
            int to = cond[1];
            if (graph[from][to]==0) {
                graph[from][to] = 1;
                in_degree[to]++;
            }
        }

        // Add all the nodes with in_node 0 to the queue
        for (int i=0; i<=k; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // Main while loop
        while (!q.empty()) {
            int current_node = q.front();
            sorted_arr.push_back(current_node);
            // For each outgoing edge
            for (int i=0; i<=k; i++) {
                if (graph[current_node][i] > 0) {
                    in_degree[i]--;
                    if (in_degree[i]==0) {
                        q.push(i);
                    }
                }
            }
        q.pop();
        }

        // Finally check if any nodes remain
        if (sorted_arr.size() != k) {
            is_cyclic = true;
        }

        return is_cyclic;
    }

    void printVec(vector<int>& vec) {
        for (auto& elem: vec) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    void printMat(vector<vector<int>>& mat) {
        for (auto& vec: mat) {
            printVec(vec);
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> rowConditions = {{1,2},{7,3},{4,3},{5,8},{7,8},{8,2},{5,8},{3,2},{1,3},{7,6},{4,3},{7,4},{4,8},{7,3},{7,5}};
    vector<vector<int>> colConditions = {{5,7},{2,7},{4,3},{6,7},{4,3},{2,3},{6,2}};
    vector<bool> valid_ints(401, false);
    vector<int> sorted;
    vector<vector<int>> mat = s.buildMatrix(8, rowConditions, colConditions);
    s.printMat(mat);
    return 0;
}