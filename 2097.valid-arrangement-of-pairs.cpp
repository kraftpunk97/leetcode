/*
 * @lc app=leetcode id=2097 lang=cpp
 *
 * [2097] Valid Arrangement of Pairs
 */
#include <bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Find the number of nodes
        set<int> nodes_set;
        for (auto pair: pairs) {
            int start = pair[0];
            int end = pair[1];
            nodes_set.insert(start);
            nodes_set.insert(end);
        }
        vector<int> nodes;
        int largest_elem = 0;
        for (int node: nodes_set) {
            largest_elem = max(largest_elem, node); 
            nodes.push_back(node);
        }
        int n = nodes.size();
        
        // Build graph representation
        vector<int> in_degree(largest_elem+1, 0);
        vector<int> out_degree(largest_elem+1, 0);

        vector<vector<int>> graph(largest_elem+1, vector<int>());
        for (auto pair: pairs) {
            int start = pair[0];
            int end = pair[1];
            graph[start].push_back(end);
            out_degree[start]++; in_degree[end]++;
        }

        // Checking for Eulerian path
        // Condition = At most one vertex has outdegree - indegree = 1
        // At most one vertex has indegree - outdegree = 1
        // All other vertecies have equal in-out degrees
        int out_minus_in = 0;
        int in_minus_out = 0;
        int equal = 0;
        int valid_start = -1;
        int other_start=0;
        for (int node: nodes) {
            if (out_degree[node] > 0) { other_start = node; }
            if (out_degree[node]-in_degree[node] == 1) { 
                out_minus_in++;
                valid_start = node;
            }
            if (in_degree[node]-out_degree[node] == 1) { 
                in_minus_out++;
            }
            if (out_degree[node] == in_degree[node]) { equal++; }
        }
        valid_start = valid_start==-1 ? other_start : valid_start;
        assert(out_minus_in+in_minus_out+equal == nodes.size());

        vector<int> solution;
        EulerianDFS(solution, graph, out_degree, valid_start);

        // Reverse the solution vector and generate `start-end` pairs
        reverse(solution.begin(), solution.end());
        for (auto i: solution) {
            cout << i << ' ';
        }
        cout << '\n';

        vector<vector<int>> result;
        int start, end;
        for (int i=1; i<solution.size(); i++) {
            int start = solution[i-1];
            int end = solution[i];

            result.push_back(vector<int>({start, end}));
        }
        return result;
    }

    void EulerianDFS(vector<int>& solution, vector<vector<int>>& graph,
                     vector<int>& out_degree, int current_node) {
        vector<int> outgoing_nodes = graph[current_node];
        while (out_degree[current_node] != 0) {
            int next_valid_node = outgoing_nodes[out_degree[current_node]];
            out_degree[current_node]--;
            EulerianDFS(solution, graph, out_degree, next_valid_node);
        }
        solution.push_back(current_node);
    }
};
// @lc code=end

int main() {
    vector<vector<int>> pairs({{1,3},{3,2},{2,1}});
    Solution s;
    s.validArrangement(pairs);
}