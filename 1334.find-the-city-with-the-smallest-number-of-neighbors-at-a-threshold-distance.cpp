/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist_graph(n, vector<int>(n, 10001));

        // Now we apply Floyd-Warshall to the problem
        floydWarshall(edges, n, dist_graph);

        //printMat(dist_graph);
        
        // We know now the shortest distance between all possible pairs of cities
        int min_cities_idx = 0;
        vector<int> counter(n, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j && dist_graph[i][j]<=distanceThreshold) {
                    counter[i]++;
                }
            }
        }

        for (int city=0; city<n; city++) {
            min_cities_idx = counter[city]<=counter[min_cities_idx] ? city : min_cities_idx;
        }
        return min_cities_idx;
    }

    void floydWarshall(vector<vector<int>> &edges, int n, vector<vector<int>> &dist_graph) {         
        for (auto edge: edges) {
            int from  = edge[0];
            int to = edge[1];
            int weight = edge[2];

            dist_graph[from][to] = weight;
            dist_graph[to][from] = weight;
        }

        for (int i=0; i<n; i++) { dist_graph[i][i] = 0; }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    dist_graph[i][j] = min(dist_graph[i][j],
                                           dist_graph[i][k] + dist_graph[k][j]);
                }
            }
        }
    }

    void printMat(vector<vector<int>> &graph) {
        for (auto vec: graph) {
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
    vector<vector<int>> edges{{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << (int) s.findTheCity(4, edges, 4) << '\n';
    return 0;
}