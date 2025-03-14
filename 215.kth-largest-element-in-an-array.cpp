/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int heapSize;
        int res;
        if (k < n/2) { // Use minHeap
            priority_queue<int, vector<int>, greater<int>> minHeap;
            heapSize = k;
            for (int num: nums) {
                minHeap.push(num);
                if (minHeap.size() > heapSize) { minHeap.pop(); } 
            }
            res = minHeap.top();
        } else { // Use maxHeap
            priority_queue<int, vector<int>> maxHeap;
            heapSize = n - k + 1;
            for (int num: nums) {
                maxHeap.push(num);
                if (maxHeap.size() > heapSize) { maxHeap.pop(); }            
            }
            res = maxHeap.top();
        }
        return res;
    }
};
// @lc code=end

