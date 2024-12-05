/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> endpoints(2*n, vector<int>(2, 0));
        
        for (int i=0, j=0; i<n; i++) {            
            // Starting point
            endpoints[j][0] = intervals[i][0];
            endpoints[j][1] = 1; 
            j++;

            // End point
            endpoints[j][0] = intervals[i][1]+1;
            endpoints[j][1] = -1; 
            j++;
        }
        
        /*
        sort(endpoints.begin(), endpoints.end(), [](vector<int> a, vector<int> b) {
            if (a[0] < b[0]) { return true; }
            else { return (a[0]==b[0]) && (a[1]<=b[1]); }
        });
        */
        sort(endpoints.begin(), endpoints.end());
        
        // Find the max overlap in a pass
        int concurrent_intr = 0; // The number of concurrent intervals at a given timestep.
        int max_overlap = 0;
        for (auto endpoint: endpoints) {
            concurrent_intr += endpoint[1];
            max_overlap = max(max_overlap, concurrent_intr);
        }

        return max_overlap;
    }

    void printVec(vector<int> &vec) {
        for (auto elem: vec) {
            cout << elem << ' ';
        }
        cout << '\n';
    }

    void printMat(vector<vector<int>> &mat) {
        for (auto vec: mat) {
            printVec(vec);
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;

    return 0;
}