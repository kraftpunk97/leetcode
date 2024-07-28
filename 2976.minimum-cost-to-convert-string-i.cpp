/*
 * @lc app=leetcode id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

// @lc code=start
class Solution {
public:
    struct pairhash {
        public:
        size_t operator()(const pair<char, char> &x) const {
            return hash<int>()((int)(x.first)) ^ hash<int>()((int)(x.second));
        }
    };

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long>> dist_graph(26, vector<long>(26, INT_MAX));

        // Apply Floyd-Warshall to obtain minimum cost.
        // Using Floyd-Warshall because the graph may contain cycles.
        floydWarshall(dist_graph, original, changed, cost);

        int n = source.size();
        long long min_cost = 0;
        for (int i=0; i<n; i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';

            if (dist_graph[from][to] == INT_MAX) { return -1; }

            min_cost += dist_graph[from][to];
        }
        return min_cost;
    }

    void floydWarshall(vector<vector<long>> &dist_graph, vector<char> &original,
                       vector<char> &changed, vector<int> &costs) {
        // Init graph
        for (int i=0; i<original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            int cost = costs[i];
            // Apparently there can be multiple (original, changed) pairs with different costs.
            // Which is just stupid, but so is Leetcode. WCYD :shrug:
            dist_graph[from][to] = min((long) cost, dist_graph[from][to]);
        }

        for (int i=0; i<26; i++) { dist_graph[i][i] = 0; }

        for (int k=0; k<26; k++) {
            for (int from=0; from<26; from++) {
                for (int to=0; to<26; to++) {
                    if (dist_graph[from][k]<INT_MAX && dist_graph[k][to]<INT_MAX) {
                        dist_graph[from][to] = min(dist_graph[from][to],
                                                   dist_graph[from][k] + dist_graph[k][to]);
                    }
                }
            }
        }
    }

    bool isUnique(vector<char> &original, vector<char> &changed) {
        unordered_set<pair<char, char>, pairhash> unique_set;

        int n = original.size();
        for (int i=0; i<n; i++) {
            char from = original[i];
            char to = changed[i];
            pair<char, char> p = pair<char, char>(from, to);

            if (unique_set.count(p) == 0) {
                unique_set.insert(pair<char, char>(from, to));
            } else { return false; }
        }

        return true;
    }
};
// @lc code=end

int main() {
    vector<char> original{'b','w','u','p','v','b','v','h','a','n','b','v','s','o','w','a','y','o','h','u','b','p','z','v','z','w','n','l','n','y','b','p','a','m','s','w','z','n','s','z','u','a','s','l','a','m','y','o','s','l','u','e','y','l','z','e','h','u','u','z','l','w','n','w','m','o','a','o','o','s','e','e','z','v','p','p','n','l','b','n','y','p','v','s','n','m','y','h','i','l','i','y','i','m','e','s','v','z','h','o','o','l','v','z','i','s','h','h','e','e','e','o','z','p','z','v','n','s','a','v','i','o','i','o','v','w','b','n','i','v','s','b','l','u','e','p','z','u','p','b','y','y','a','u','a','i','n','l','n','u','v','b','h','w','l','e','m','p','y','n','m','h','a','p','w','l','i','b','p','m','i','a','i','e','s','h','e','u','w','m','y','n','m','w','m'};
    vector<char> changed{'y','z','w','u','z','e','l','v','l','w','u','h','o','a','m','h','n','h','w','o','w','b','i','p','m','y','b','e','m','i','s','a','b','e','v','v','o','l','y','h','y','u','z','s','p','p','b','b','w','u','z','m','l','p','b','s','m','n','m','a','i','e','h','b','v','s','z','p','l','i','l','z','u','w','h','z','e','h','v','o','o','s','y','h','a','n','u','z','z','y','n','e','y','l','h','e','m','y','o','m','n','z','u','s','u','b','u','i','y','o','n','u','v','i','l','e','p','a','w','b','p','z','v','w','a','h','l','v','a','i','l','m','n','e','w','w','w','b','e','o','z','s','e','l','o','b','s','m','y','i','o','p','b','i','v','u','b','l','v','u','s','e','v','v','p','o','w','i','m','w','h','s','s','a','u','l','b','a','n','o','p','z','y','a','z'};
    Solution s;
    cout << boolalpha << s.isUnique(original, changed) << '\n';
    return 0;
}