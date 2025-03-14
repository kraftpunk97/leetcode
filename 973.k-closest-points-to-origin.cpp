/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparatorFunc = [](vector<int>& a, vector<int>& b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparatorFunc)> minHeap{comparatorFunc};

        for (auto point: points) {
            minHeap.push(point);
            if (minHeap.size() > k) { minHeap.pop(); }
        }

        vector<vector<int>> result(k, vector<int>(0, 2));
        int i = 0;
        while (!minHeap.empty()) {
            result[i++] = minHeap.top();
            minHeap.pop();
        }
        return result;
    }
};
// @lc code=end

