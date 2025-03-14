/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        for (int stone: stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() >= 2) {
            int heaviestStone = maxHeap.top();
            maxHeap.pop();
            int secHeaviestStone = maxHeap.top();
            maxHeap.pop();
            int diff = heaviestStone - secHeaviestStone;
            if (diff > 0) {
                maxHeap.push(diff);
            }
        }

        return maxHeap.size()==1 ? maxHeap.top() : 0;
    }

};
// @lc code=end

