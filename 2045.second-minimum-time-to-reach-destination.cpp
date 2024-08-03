/*
 * @lc app=leetcode id=2045 lang=cpp
 *
 * [2045] Second Minimum Time to Reach Destination
 */
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Set up the graph first
        vector<vector<int>> graph(n+1, vector<int>(n+1, -1));

        for (int i=1; i<=n; i++) { graph[i][i] = 0; }
        for (auto edge: edges) {
            int from = edge[0];
            int to = edge[1];
            graph[from][to] = time;
            graph[to][from] = time;
        }   

        // Some kind of BFS?
        queue<int> q;
        vector<bool> seen(n+1, false);
        q.push(1);
        seen[1] = true;
        while (!q.empty()) {
            int curr_node = q.front();
            // Do something here.
            q.pop();
            for (int j=1; j<=n; j++) {
                if (graph[curr_node][j]>0 && (!seen[j])) {
                    seen[j] = true;
                    q.push(j);
                }
            }
        }
    }

    void dijkstra(vector<vector<int>> &graph, int n) {
        vector<int> dist(n+1, -1);
        vector<int> prev(n+1, 0);
        vector<bool> Q(n+1, true);
        int Q_counter = n;

        dist[1] = 0;

        while (Q_counter > 0) {
            int min_dist = INT_MAX;
            int min_dist_idx = 0;

            // Select the vertex with the minimum distance
            for (int i=1; i<=n; i++) {
                if (Q[i] && dist[i]<min_dist) {
                    min_dist = dist[i];
                    min_dist_idx = i;
                }
            }

            // Remove this vertex from Q
            Q[min_dist_idx] = false;
            Q_counter--;

            for (int to=1; to<=n; to++) {
                if (graph[min_dist_idx][to]>0 && Q[to]) {
                    int alt = dist[min_dist_idx] + graph[min_dist_idx][to];
                    if (alt < dist[to]) {
                        dist[to] = alt;
                        prev[to] = min_dist_idx;
                    }
                }
            }
        }
    }
};
// @lc code=end

